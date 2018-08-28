## 三、链表

### 1. 链表的特性

真正的动态数据结构（可以动态地增加元素，容量不是一开始就指定了），插入数据不需要像数组一样移动数据，因此时间复杂度低。但是访问数据则不能直接通过索引来访问，实际上也没有索引，因此访问的话时间复杂度就高了起来。

java代码：

```java
public class LinkedList<E> {
	//节点作为内部类。
    private class Node{
        public E e;
        public Node next;

        public Node(E e, Node next){
            this.e = e;
            this.next = next;
        }

        public Node(E e){
            this(e, null);
        }

        public Node(){
            this(null, null);
        }

        @Override
        public String toString(){
            return e.toString();
        }
    }

    private Node head;
    private int size;

    public LinkedList(){
        head = null;
        size = 0;
    }

    // 获取链表中的元素个数
    public int getSize(){
        return size;
    }

    // 返回链表是否为空
    public boolean isEmpty(){
        return size == 0;
    }

    // 在链表头添加新的元素e
    public void addFirst(E e){
//        Node node = new Node(e);
//        node.next = head;
//        head = node;

        head = new Node(e, head);
        size ++;
    }

    // 在链表的index(0-based)位置添加新的元素e
    // 在链表中不是一个常用的操作，练习用：）
    public void add(int index, E e){

        if(index < 0 || index > size)
            throw new IllegalArgumentException("Add failed. Illegal index.");

        if(index == 0)
            addFirst(e);
        else{
            Node prev = head;
            for(int i = 0 ; i < index - 1 ; i ++)
                prev = prev.next;

//            Node node = new Node(e);
//            node.next = prev.next;
//            prev.next = node;

            prev.next = new Node(e, prev.next);
            size ++;
        }
    }

    // 在链表末尾添加新的元素e
    public void addLast(E e){
        add(size, e);
    }
}
```

c++代码：

```c++
#include<assert.h>
template<typename T>
class Node {
public:	
	T e;
	T* next;
public:
	Node() {
		this->next = nullptr;
	}
	Node(T e) {
		this->e = e;
		this->next = nullptr;
	}
	Node(T e, Node<T> *node) {
		this->e = e;
		this->next = node;
	}
};

template<typename T>
class LinkedList {
private:
	Node<T> head;
	int size;
public:
	LinkedList() {
		this->head = nullptr;
		this->size = 0;
	}

	int getSize() {
		return this->size;
	}
	bool isEmpty() {
		return this->size == 0;
	}

	void addFist(T e) {
		/*Node<T> *node = new Node<T>(e);
		node->next = this->head;
		this->head = node;*/

		this->head = new Node<T>(e, this->head);
		this->size++;
	}

	// 在链表的index(0-based)位置添加新的元素e
	// 在链表中不是一个常用的操作，练习用：）
	void add(int index, T e) {
		assert(index >= 0 && index <= size);
		if (index == 0) {
			this->addFist(e);
		}
		else {
			Node<T> *prev = this->head;
			for (int i = 0; i < index - 1; i++) {
				prev = prev->next;
			}
			Node<T> *node=new Node<T>(e);
			node->next = prev->next;
			prev->next = node;
			this->size++;
		}
	}

	// 在链表末尾添加新的元素e
	void addLast(T e) {
		this->add(this->size, e);
	}
};
```

### 2. 虚拟节点

以上的这种情况需要特殊考虑头节点，这是因为头结点没有前节点，因此需要特殊操作。如果考虑在头节点之前建立一个虚拟节点，那么就可以不需要对头结点进行特殊处理了。

特别注意：使用了dummyHead之后，就不使用head了。而且，往链表中添加元素等操作的逻辑也发生了改变。

### 3. 链表元素的遍历，查询，修改和删除。

注意一点：所有prev和cur代表的意思就是我想要进行某种操作的元素的**前一个**或者**当前这个**。

java代码：

```java
public class LinkedList<E> {

    private class Node{
        public E e;
        public Node next;

        public Node(E e, Node next){
            this.e = e;
            this.next = next;
        }

        public Node(E e){
            this(e, null);
        }

        public Node(){
            this(null, null);
        }

        @Override
        public String toString(){
            return e.toString();
        }
    }

    private Node dummyHead;
    private int size;

    public LinkedList(){
        //初始化是不是有错？为什么不需要传入头结点的指针？
        dummyHead = new Node();
        size = 0;
    }

    // 获取链表中的元素个数
    public int getSize(){
        return size;
    }

    // 返回链表是否为空
    public boolean isEmpty(){
        return size == 0;
    }

    // 在链表的index(0-based)位置添加新的元素e
    // 在链表中不是一个常用的操作，练习用：）
    public void add(int index, E e){

        if(index < 0 || index > size)
            throw new IllegalArgumentException("Add failed. Illegal index.");

        Node prev = dummyHead;
        for(int i = 0 ; i < index ; i ++)
            prev = prev.next;

        prev.next = new Node(e, prev.next);
        size ++;
    }

    // 在链表头添加新的元素e
    public void addFirst(E e){
        add(0, e);
    }

    // 在链表末尾添加新的元素e
    public void addLast(E e){
        add(size, e);
    }

    // 获得链表的第index(0-based)个位置的元素
    // 在链表中不是一个常用的操作，练习用：）
    public E get(int index){

        if(index < 0 || index >= size)
            throw new IllegalArgumentException("Get failed. Illegal index.");

        Node cur = dummyHead.next;//注意这里指向的是虚拟节点的next。
        for(int i = 0 ; i < index ; i ++)
            cur = cur.next;
        return cur.e;
    }

    // 获得链表的第一个元素
    public E getFirst(){
        return get(0);
    }

    // 获得链表的最后一个元素
    public E getLast(){
        return get(size - 1);
    }

    // 修改链表的第index(0-based)个位置的元素为e
    // 在链表中不是一个常用的操作，练习用：）
    public void set(int index, E e){
        if(index < 0 || index >= size)
            throw new IllegalArgumentException("Set failed. Illegal index.");

        Node cur = dummyHead.next;
        for(int i = 0 ; i < index ; i ++)
            cur = cur.next;
        cur.e = e;
    }

    // 查找链表中是否有元素e
    public boolean contains(E e){
        Node cur = dummyHead.next;
        while(cur != null){
            if(cur.e.equals(e))
                return true;
            cur = cur.next;
        }
        return false;
    }

    // 从链表中删除index(0-based)位置的元素, 返回删除的元素
    // 在链表中不是一个常用的操作，练习用：）
    public E remove(int index){
        if(index < 0 || index >= size)
            throw new IllegalArgumentException("Remove failed. Index is illegal.");

        Node prev = dummyHead;
        for(int i = 0 ; i < index ; i ++)
            prev = prev.next;

        Node retNode = prev.next;
        prev.next = retNode.next;
        retNode.next = null;
        size --;

        return retNode.e;
    }

    // 从链表中删除第一个元素, 返回删除的元素
    public E removeFirst(){
        return remove(0);
    }

    // 从链表中删除最后一个元素, 返回删除的元素
    public E removeLast(){
        return remove(size - 1);
    }

    // 从链表中删除元素e
    public void removeElement(E e){

        Node prev = dummyHead;
        while(prev.next != null){
            if(prev.next.e.equals(e))
                break;
            prev = prev.next;
        }

        if(prev.next != null){
            Node delNode = prev.next;
            prev.next = delNode.next;
            delNode.next = null;
            size --;
        }
    }

    @Override
    public String toString(){
        StringBuilder res = new StringBuilder();

        Node cur = dummyHead.next;
        while(cur != null){
            res.append(cur + "->");
            cur = cur.next;
        }
        res.append("NULL");

        return res.toString();
    }
}
```

c++代码：

```c++
#include<assert.h>
#include <iostream>
template<typename T>
class Node {
public:
	T e;
	Node<T>* next;
public:
	Node() {
		this->next = nullptr;
	}
	Node(T e) {
		this->e = e;
		this->next = nullptr;
	}
	Node(T e, Node<T> *node) {
		this->e = e;
		this->next = node;
	}

};

template<typename T>
class LinkedList {
private:
	Node<T> *dummyHead;
	int size;
public:
	LinkedList() {
		this->dummyHead = new Node<T>();
		this->size = 0;
	}
	~LinkedList() {
		int size = this->size;
		for (int i = 0; i < size; i++) {
			this->removeFirst();
		}
	}

	int getSize() {
		return this->size;
	}
	bool isEmpty() {
		return this->size == 0;
	}


	// 在链表的index(0-based)位置添加新的元素e
	// 在链表中不是一个常用的操作，练习用：）
	void add(int index, T e) {
		assert(index >= 0 && index <= size);
		if (index == 0) {
			this->dummyHead->next=new Node<T>(e,this->dummyHead->next);
			this->size++;
		}
		else {
			Node<T> *prev = this->dummyHead;
			for (int i = 0; i < index ; i++) {
				prev = prev->next;
			}
			/*Node<T> *node=new Node<T>(e);
			node->next = prev->next;
			prev->next = node;*/
			prev->next = new Node<T>(e, prev->next);
			this->size++;
		}
	}
	void addFirst(T e) {
		this->add(0, e);
	}

	// 在链表末尾添加新的元素e
	void addLast(T e) {
		this->add(this->size, e);
	}

	// 获得链表的第index(0-based)个位置的元素
	// 在链表中不是一个常用的操作，练习用：）
	T get(int index) {

		assert(index >= 0 && index < size);

		Node<T> *cur = this->dummyHead->next;
		for (int i = 0; i < index; i++)
			cur = cur->next;
		return cur->e;
	}

	// 获得链表的第一个元素
	T getFirst() {
		return this->get(0);
	}

	// 获得链表的最后一个元素
	T getLast() {
		return this->get(size - 1);
	}

	// 修改链表的第index(0-based)个位置的元素为e
	// 在链表中不是一个常用的操作，练习用：）
	void set(int index, T e) {
		assert(index >= 0 && index < size);
		Node<T> *cur = dummyHead->next;
		for (int i = 0; i < index; i++)
			cur = cur->next;
		cur->e = e;
	}

	// 查找链表中是否有元素e
	bool contains(T e) {
		Node<T> *cur = this->dummyHead->next;
		while (cur != nullptr) {
			if (cur->e == e) {
				return true;
			}
			cur = cur->next;
		}
		return false;
	}
	// 从链表中删除index(0-based)位置的元素, 返回删除的元素
	// 在链表中不是一个常用的操作，练习用：）
	T remove(int index) {
		assert(index >= 0 && index < size);
		Node<T> *prev = this->dummyHead;
		for (int i = 0; i < index; i++) {
			prev = prev->next;
		}
		Node<T> *retNode = prev->next;
		T e = retNode->e;
		prev->next = retNode->next;
		delete retNode;
		this->size--;

		return e;
	}

	// 从链表中删除第一个元素, 返回删除的元素
	T removeFirst() {
		return remove(0);
	}

	// 从链表中删除最后一个元素, 返回删除的元素
	T removeLast() {
		return remove(size - 1);
	}

	// 从链表中删除元素e，此时假定链表中
	void removeElement(T e) {

		Node<T> *prev = this->dummyHead;
		while (prev->next != nullptr) {
			if (prev->next->e == e) {
				break;
			}
			prev = prev->next;
		}

		if (prev.next != null) {
			Node<T> *delNode = prev->next;
			prev->next = delNode->next;
			delete delNode;
			this->size--;
		}
	}
	friend std::ostream & operator<<(std::ostream & out, LinkedList & linkedList) {
		Node<T> *cur = linkedList.dummyHead->next;
		while (cur != nullptr) {
			out << cur->e<<" ";
			cur = cur->next;
		}
		out << std::endl;
		return out;
	}
};
//==================================================================
# include "linkedList.h"
int main() {
	LinkedList<int> linkedList;
	for (int i = 0; i < 5; i++) {
		linkedList.addFirst(i);
		std::cout << linkedList;
	}
	linkedList.add( 2, 666);
	std::cout << linkedList;

	linkedList.remove(2);
	std::cout << linkedList;
	linkedList.removeFirst();
	std::cout << linkedList;
	linkedList.removeLast();
	std::cout << linkedList;
}
```



### 4. 链表时间复杂度分析

pass

### 5. 用链表来写stack

java代码：

```java
public class LinkedListStack<E> implements Stack<E> {

    private LinkedList<E> list;

    public LinkedListStack(){
        list = new LinkedList<>();
    }

    @Override
    public int getSize(){
        return list.getSize();
    }

    @Override
    public boolean isEmpty(){
        return list.isEmpty();
    }

    @Override
    public void push(E e){
        list.addFirst(e);
    }

    @Override
    public E pop(){
        return list.removeFirst();
    }

    @Override
    public E peek(){
        return list.getFirst();
    }

    @Override
    public String toString(){
        StringBuilder res = new StringBuilder();
        res.append("Stack: top ");
        res.append(list);
        return res.toString();
    }

    public static void main(String[] args) {

        LinkedListStack<Integer> stack = new LinkedListStack<>();

        for(int i = 0 ; i < 5 ; i ++){
            stack.push(i);
            System.out.println(stack);
        }

        stack.pop();
        System.out.println(stack);
    }
}
```

c++代码：

```c++
#include<iostream>
#include"linkedList.h"
template<typename T>
class LinkedListStack {
private:
	LinkedList<T> *list;
public:
	LinkedListStack() {
		this->list = new LinkedList<T>();
	}
	int getSize() {
		return list->getSize();
	}

	bool isEmpty() {
		return list->isEmpty();
	}

	void push(T e) {
		list->addFirst(e);
	}

	T pop() {
		return list->removeFirst();
	}

	T peek() {
		return list->getFirst();
	}

	void print() {
		std::cout << this->list;
	}
};
```

### 6. 用链表来写队列

java代码实现：

```java
public class LinkedListQueue<E> implements Queue<E> {

    private class Node{
        public E e;
        public Node next;

        public Node(E e, Node next){
            this.e = e;
            this.next = next;
        }

        public Node(E e){
            this(e, null);
        }

        public Node(){
            this(null, null);
        }

        @Override
        public String toString(){
            return e.toString();
        }
    }

    private Node head, tail;
    private int size;

    public LinkedListQueue(){
        head = null;
        tail = null;
        size = 0;
    }

    @Override
    public int getSize(){
        return size;
    }

    @Override
    public boolean isEmpty(){
        return size == 0;
    }

    @Override
    public void enqueue(E e){
        if(tail == null){
            tail = new Node(e);
            head = tail;
        }
        else{
            tail.next = new Node(e);
            tail = tail.next;
        }
        size ++;
    }

    @Override
    public E dequeue(){
        if(isEmpty())
            throw new IllegalArgumentException("Cannot dequeue from an empty queue.");

        Node retNode = head;
        head = head.next;
        retNode.next = null;
        if(head == null)
            tail = null;
        size --;
        return retNode.e;
    }

    @Override
    public E getFront(){
        if(isEmpty())
            throw new IllegalArgumentException("Queue is empty.");
        return head.e;
    }

    @Override
    public String toString(){
        StringBuilder res = new StringBuilder();
        res.append("Queue: front ");

        Node cur = head;
        while(cur != null) {
            res.append(cur + "->");
            cur = cur.next;
        }
        res.append("NULL tail");
        return res.toString();
    }

    public static void main(String[] args){

        LinkedListQueue<Integer> queue = new LinkedListQueue<>();
        for(int i = 0 ; i < 10 ; i ++){
            queue.enqueue(i);
            System.out.println(queue);

            if(i % 3 == 2){
                queue.dequeue();
                System.out.println(queue);
            }
        }
    }
}
```

c++代码实现:

```c++
#include<iostream>
#include"linkedList.h"
template<typename T>
class LinkedListStack {
private:
	LinkedList<T> *list;
public:
	LinkedListStack() {
		this->list = new LinkedList<T>();
	}
	int getSize() {
		return list->getSize();
	}

	bool isEmpty() {
		return list->isEmpty();
	}

	void push(T e) {
		list->addFirst(e);
	}

	T pop() {
		return list->removeFirst();
	}

	T peek() {
		return list->getFirst();
	}

	void print() {
		std::cout << this->list;
	}
};
//=======================================
# include "linkedListStack.h"

int main() {
	int opCount = 100000;
	LinkedListStack<int> *linkedListStack = new LinkedListStack<int>();
	for (int i = 0; i < opCount; i++) {
		linkedListStack->push(i);
	}
	for (int i = 0; i < opCount; i++) {
		linkedListStack->pop();
	}
	std::cout << "Done!" << std::endl;
	// 其实这个时间比较很复杂，因为LinkedListStack中包含更多的new操作

}
```

