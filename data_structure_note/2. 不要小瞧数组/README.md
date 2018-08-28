## 一、数组

### 1. 一些注意点：

1. 数组索引可以有语义信息，比如学号，但是并不是有语义信息的索引都适用于数组，比如身份证号。
2. 数组有点：根据索引快速查询。

### 2. 重新封装数组

#### 功能

- 增加元素（数组末，数组开头，任意指定位置）
- 查询元素
- 修改元素
- 是否包含元素
- 搜索元素
- 删除元素

### 3. 使用泛型

java中使用泛型不能直接使用基本数据类型，只能是类对象。因此要讲基本数据类型搞成包装类，这个在java中已经做好了，不需要我们再去做。

### 4. 综合代码

java代码：

```java
// E表示泛型
public class Array<E> {
    //java中定义数组的方法E[]
    //成员函数中没有容量capacity这一项。而是通过直接求data的长度得到。
    private E[] data;
    private int size;

    // 构造函数，传入数组的容量capacity构造Array
    public Array(int capacity){
        //注意，在java中不能通过new E(capacity)这种方法进行建立数组，只能通过所有类的父类Object来建立数组，然后再通过（E[]）进行强制类型转换。
        data = (E[])new Object[capacity];
        size = 0;
    }

    // 无参数的构造函数，默认数组的容量capacity=10
    public Array(){
        //这里应该是使用到了成员函数重载的功能，this（10）因为有一个参数传进去，所以会默认调用上面那个构造函数。
        this(10);
    }

    // 获取数组的容量
    public int getCapacity(){
        return data.length;
    }

    // 获取数组中的元素个数
    public int getSize(){
        return size;
    }

    // 返回数组是否为空
    public boolean isEmpty(){
        return size == 0;
    }

    // 在index索引的位置插入一个新元素e
    // 注意index的值是0-based.index=size,那么就在最后一个元素之后插入。
    public void add(int index, E e){

        if(size == data.length)
            throw new IllegalArgumentException("Add failed. Array is full.");

        if(index < 0 || index > size)
            throw new IllegalArgumentException("Add failed. Require index >= 0 and index <= size.");

        for(int i = size - 1; i >= index ; i --)
            data[i + 1] = data[i];

        data[index] = e;

        size ++;
    }

    // 向所有元素后添加一个新元素
    public void addLast(E e){
        add(size, e);
    }

    // 在所有元素前添加一个新元素
    public void addFirst(E e){
        add(0, e);
    }

    // 获取index索引位置的元素
    public E get(int index){
        if(index < 0 || index >= size)
            throw new IllegalArgumentException("Get failed. Index is illegal.");
        return data[index];
    }

    // 修改index索引位置的元素为e
    public void set(int index, E e){
        if(index < 0 || index >= size)
            throw new IllegalArgumentException("Set failed. Index is illegal.");
        data[index] = e;
    }

    // 查找数组中是否有元素e
    public boolean contains(E e){
        for(int i = 0 ; i < size ; i ++){
            if(data[i].equals(e))
                return true;
        }
        return false;
    }

    // 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
    public int find(E e){
        for(int i = 0 ; i < size ; i ++){
            if(data[i].equals(e))
                return i;
        }
        return -1;
    }

    // 从数组中删除index位置的元素, 返回删除的元素
    public E remove(int index){
        if(index < 0 || index >= size)
            throw new IllegalArgumentException("Remove failed. Index is illegal.");

        E ret = data[index];
        for(int i = index + 1 ; i < size ; i ++)
            data[i - 1] = data[i];
        size --;
        // 涉及到java的垃圾回收机制，这里暂时不用管这个。这句可以直接注释掉也没关系。
        data[size] = null; // loitering objects != memory leak
        return ret;
    }

    // 从数组中删除第一个元素, 返回删除的元素
    public E removeFirst(){
        return remove(0);
    }

    // 从数组中删除最后一个元素, 返回删除的元素
    public E removeLast(){
        return remove(size - 1);
    }

    // 从数组中删除元素e
    public void removeElement(E e){
        int index = find(e);
        if(index != -1)
            remove(index);
    }

    @Override
    public String toString(){

        StringBuilder res = new StringBuilder();
        res.append(String.format("Array: size = %d , capacity = %d\n", size, data.length));
        res.append('[');
        for(int i = 0 ; i < size ; i ++){
            res.append(data[i]);
            if(i != size - 1)
                res.append(", ");
        }
        res.append(']');
        return res.toString();
    }
}
```

c++代码

```c++
#include<assert.h>
#include <iostream>
template<typename T>
class Array{
private:
	T *data;
	int capacity;
	int size;
	
public:
	// 构造函数，传入数组的容量capacity构造Array
	Array(int capacity) {
		this->capacity = capacity;
		this->data = new T[capacity];
		this->size = 0;
	}

	// 无参数的构造函数，默认数组的容量capacity=10
	Array() {
		this->Array(10);
	}

	~Array() {
		delete[]this->data;
	}

	// 获取数组的容量
	int getCapacity() {
		return this->capacity;
	}

	// 获取数组中的元素个数
	int getSize() {
		return this->size;
	}

	// 返回数组是否为空
	bool isEmpty() {
		return this->size == 0;
	}

	// 在index索引的位置插入一个新元素e
	void add(int index,T e) { 

		assert(this->size < capacity);
		assert(index >= 0 && index <= this->size);
		for (int i = this->size ; i > index; i--) {
			this->data[i] = this->data[i - 1];
		}
		/*for (int i = this->size - 1; i >= index; i--)
			this->data[i + 1] = this->data[i];*/

		this->data[index] = e;
		this->size++;
	}

	// 向所有元素后添加一个新元素
	void addLast(T e) {
		this->add(this->size, e);
	}

	// 在所有元素前添加一个新元素
	void addFirst(T e) {
		this->add(0, e);
	}

	// 获取index索引位置的元素
	T get(int index) {
		assert(index >= 0 && index < size);
		return this->data[index];
	}

	// 修改index索引位置的元素为e
	void set(int index, T e) {
		assert(index >= 0 && index < size);
		this->data[index] = e;
	}

	// 查找数组中是否有元素e
	bool contains(T e) {
		for (int i = 0; i < size; i++) {
			if (this->data[i] == e) {
				return true;
			}	
		}
		return false;
	}

	// 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
	int find(T e) {
		for (int i = 0; i < size; i++) {
			if (data[i]==e)
				return i;
		}
		return -1;
	}

	// 从数组中删除index位置的元素, 返回删除的元素
	T remove(int index) {
		assert(index >= 0 && index < size);
		T ret = this->data[index];
		for (int i = index; i < size-1; i++)
			data[i] = data[i+1];
		/*for (int i = index + 1; i < size; i++)
			data[i - 1] = data[i];*/
		this->size--;
		return ret;
	}

	// 从数组中删除第一个元素, 返回删除的元素
	T removeFirst() {
		return this->remove(0);
	}

	// 从数组中删除最后一个元素, 返回删除的元素
	T removeLast() {
		return this->remove(this->size - 1);
	}

	// 从数组中删除元素e
	void removeElement(T e) {
		int index = this->find(e);
		if (index != -1)
			this->remove(index);
	}
	friend std::ostream & operator<<(std::ostream & out, Array & array) {
		for (int i = 0; i < array.size; i++) {
			out << array.data[i] << " ";
		}
		out << std::endl;
		return out;
	}
};
```



### 5. 动态数组

我们目前的数组的容量都是固定的，没有办法动态扩展，因此可以考虑将数组增加动态扩展的功能。

动态数组的功能：

1. 动态扩增数据容量
2. 动态缩减数据容量

java代码：

```java
public class Array<E> {

    private E[] data;
    private int size;

    // 构造函数，传入数组的容量capacity构造Array
    public Array(int capacity){
        data = (E[])new Object[capacity];
        size = 0;
    }

    // 无参数的构造函数，默认数组的容量capacity=10
    public Array(){
        this(10);
    }

    // 获取数组的容量
    public int getCapacity(){
        return data.length;
    }

    // 获取数组中的元素个数
    public int getSize(){
        return size;
    }

    // 返回数组是否为空
    public boolean isEmpty(){
        return size == 0;
    }

    // 在index索引的位置插入一个新元素e
    public void add(int index, E e){

        if(index < 0 || index > size)
            throw new IllegalArgumentException("Add failed. Require index >= 0 and index <= size.");
//========================================================================================
        if(size == data.length)
            resize(2 * data.length);
//========================================================================================
        for(int i = size - 1; i >= index ; i --)
            data[i + 1] = data[i];

        data[index] = e;

        size ++;
    }

    // 向所有元素后添加一个新元素
    public void addLast(E e){
        add(size, e);
    }

    // 在所有元素前添加一个新元素
    public void addFirst(E e){
        add(0, e);
    }

    // 获取index索引位置的元素
    public E get(int index){
        if(index < 0 || index >= size)
            throw new IllegalArgumentException("Get failed. Index is illegal.");
        return data[index];
    }

    // 修改index索引位置的元素为e
    public void set(int index, E e){
        if(index < 0 || index >= size)
            throw new IllegalArgumentException("Set failed. Index is illegal.");
        data[index] = e;
    }

    // 查找数组中是否有元素e
    public boolean contains(E e){
        for(int i = 0 ; i < size ; i ++){
            if(data[i].equals(e))
                return true;
        }
        return false;
    }

    // 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
    public int find(E e){
        for(int i = 0 ; i < size ; i ++){
            if(data[i].equals(e))
                return i;
        }
        return -1;
    }

    // 从数组中删除index位置的元素, 返回删除的元素
    public E remove(int index){
        if(index < 0 || index >= size)
            throw new IllegalArgumentException("Remove failed. Index is illegal.");

        E ret = data[index];
        for(int i = index + 1 ; i < size ; i ++)
            data[i - 1] = data[i];
        size --;
        data[size] = null; // loitering objects != memory leak
//===========================删除元素需要减少容量===========================================
        if(size == data.length / 2)
            resize(data.length / 2);
//========================================================================================
        return ret;
    }

    // 从数组中删除第一个元素, 返回删除的元素
    public E removeFirst(){
        return remove(0);
    }

    // 从数组中删除最后一个元素, 返回删除的元素
    public E removeLast(){
        return remove(size - 1);
    }

    // 从数组中删除元素e
    public void removeElement(E e){
        int index = find(e);
        if(index != -1)
            remove(index);
    }

    @Override
    public String toString(){

        StringBuilder res = new StringBuilder();
        res.append(String.format("Array: size = %d , capacity = %d\n", size, data.length));
        res.append('[');
        for(int i = 0 ; i < size ; i ++){
            res.append(data[i]);
            if(i != size - 1)
                res.append(", ");
        }
        res.append(']');
        return res.toString();
    }
//========================================================================================
    // 将数组空间的容量变成newCapacity大小
    private void resize(int newCapacity){

        E[] newData = (E[])new Object[newCapacity];
        for(int i = 0 ; i < size ; i ++)
            newData[i] = data[i];
        data = newData;
    }
}
//========================================================================================
```

c++代码：

```c++
#include<assert.h>
#include <iostream>
template<typename T>
class Array{
private:
	T *data;
	int capacity;
	int size;

private:
	// 将数组空间的容量变成newCapacity大小
	void resize(int newCapacity) {

		T *newData = new T[newCapacity];
		for (int i = 0; i < this->size; i++)
			newData[i] =this-> data[i];
		delete[]this->data;
		this->data = newData;
	}
public:
	// 构造函数，传入数组的容量capacity构造Array
	Array(int capacity) {
		this->capacity = capacity;
		this->data = new T[capacity];
		this->size = 0;
	}

	// 无参数的构造函数，默认数组的容量capacity=10
	Array() {
		this->capacity = 10;
		this->data = new T[10];
		this->size = 0;
	}

	~Array() {
		delete[]this->data;
		this->data = nullptr;
	}

	// 获取数组的容量
	int getCapacity() {
		return this->capacity;
	}

	// 获取数组中的元素个数
	int getSize() {
		return this->size;
	}

	// 返回数组是否为空
	bool isEmpty() {
		return this->size == 0;
	}

	// 在index索引的位置插入一个新元素e
	void add(int index,T e) { 

		assert(index >= 0 && index <= this->size);
		if (this->size == this->capacity) {
			this->resize(2 * this->capacity);
			this->capacity = 2 * this->capacity;
		}

		for (int i = this->size ; i > index; i--) {
			this->data[i] = this->data[i - 1];
		}
		/*for (int i = this->size - 1; i >= index; i--)
			this->data[i + 1] = this->data[i];*/

		this->data[index] = e;
		this->size++;
	}

	// 向所有元素后添加一个新元素
	void addLast(T e) {
		this->add(this->size, e);
	}

	// 在所有元素前添加一个新元素
	void addFirst(T e) {
		this->add(0, e);
	}

	// 获取index索引位置的元素
	T get(int index) {
		assert(index >= 0 && index < size);
		return this->data[index];
	}

	// 修改index索引位置的元素为e
	void set(int index, T e) {
		assert(index >= 0 && index < size);
		this->data[index] = e;
	}

	// 查找数组中是否有元素e
	bool contains(T e) {
		for (int i = 0; i < size; i++) {
			if (this->data[i] == e) {
				return true;
			}	
		}
		return false;
	}

	// 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
	int find(T e) {
		for (int i = 0; i < size; i++) {
			if (data[i]==e)
				return i;
		}
		return -1;
	}

	// 从数组中删除index位置的元素, 返回删除的元素
	T remove(int index) {
		assert(index >= 0 && index < size);
		T ret = this->data[index];
		for (int i = index; i < size-1; i++)
			data[i] = data[i+1];
		/*for (int i = index + 1; i < size; i++)
			data[i - 1] = data[i];*/
		this->size--;
		if (this->size == this->capacity / 2) {
			this->resize(this->capacity / 2);
		}
		return ret;
	}

	// 从数组中删除第一个元素, 返回删除的元素
	T removeFirst() {
		return this->remove(0);
	}

	// 从数组中删除最后一个元素, 返回删除的元素
	T removeLast() {
		return this->remove(this->size - 1);
	}

	// 从数组中删除元素e
	void removeElement(T e) {
		int index = this->find(e);
		if (index != -1)
			this->remove(index);
	}
	friend std::ostream & operator<<(std::ostream & out, Array & array) {
		for (int i = 0; i < array.size; i++) {
			out << array.data[i] << " ";
		}
		out << std::endl;
		return out;
	}
};
```



### 6. 复杂度分析

**时间复杂度概念**

$T(n)=2n^2+3n+c$：算法的总操作数目，

如果 $n->{∞}，lim (T(n)/n^2)=常数$ ，

$O(n^2)$则是时间复杂度。

**注意点**

$O(n^2)$的时间复杂度不一定小于$O(n)$。时间复杂度主要关注$n$很大的情况下来说。

复杂度分析要考虑最坏的情况。

对于动态数组而言，并不是每次都是调用resize函数，因此要进行均摊计算。