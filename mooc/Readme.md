# 数据结构

## 算法复杂度

pass

## 第一单元

学习路径

1. 线性（排序）
2. 树形
3. 图论

## 第二单元 排序算法

首先要接触的是O(n^2)的排序算法。为什么要学这个复杂度比较高的算法呢？

主要是因为：

1. 这是一个基础。基础做好了才可能在这个基础上进行改进。
2. 编码简单，易于实现。在简单情景下这个算法是可以用的。
3. 在某些情景下可能比其他的算法更有效。

### 1. 选择排序

选择排序的意思就是选择一个最小的，把它放在最前面。不断重复这个动作。

选择排序的思路：对于一堆数据，比如1,6,2,3,8,5,7,4。

1. 首先从第一个数字开始到最后一个数字结束，挑出最小的数字，与第一个数字交换。
2. 然后从第二个数字开始，到最后一个数字结束，挑出最小的数字，与第二个数字交换。
3. 不断重复...
4. 到倒数第二个（n-2）数字的时候就是最后的一步了。注意，不是到最后一个数字结束。

代码

~~~c++
#include <iostream>
#include <algorithm>
using namespace std;
void selectionSort(int arr[], int n){
    // mensaochun：这里实际上用n-1就可以了！
    for(int i = 0 ; i < n ; i ++){
        // 寻找[i, n)区间里的最小值
        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;
        swap( arr[i] , arr[minIndex] );
    }
}
int main() {
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort(a,10);
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
~~~

> 注意：这里用到了标准库中的swap算法，这个需要#include<algorithm>

### 2.使用模板编写算法

pass

### 3&4. 随机生成算法测试用例&测试算法的性能

测试的时候通常都是自己随便定义一个数组，然后测试。但是你要测试长度为几万的数组的时候就很难生成了。所以写好一个工具就很重要。

以下实现了随机数

打印

~~~c++
#ifndef INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H
#define INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H
#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;
namespace SortTestHelper {
    // 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));//设置随机种子
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }
    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }
   // 测试排序是否正确。
    template<typename T>
    bool isSorted(T arr[], int n) {

        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;

        return true;
    }
	// 传入函数指针，测试数组。
    template<typename T>
    void testSort(const string &sortName, void (*sort)(T[], int), T arr[], int n) {
        // clock_t在ctime库中。
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
        return;
    }
};
#endif //INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H
~~~



### 5.插入排序（冒泡排序）

1. 从第二个开始数字开始，和前面的数字比，如果比它小，交换位置，否则就不动。
2. 从第三个开始数字开始，和前面的数字比，如果比它小，交换位置，再继续与第一数字比...。
3. ...
4. 从最后一个数字开始（n-1）, 与前面的数字比，如果比它小，交换位置，否则不动。如此往复

为什么会收敛，这是因为从每一步都可以保证这一步之前是有序的。

~~~c++
#ifndef INC_04_INSERTION_SORT_SELECTIONSORT_H
#define INC_04_INSERTION_SORT_SELECTIONSORT_H
#include <iostream>
#include <algorithm>
using namespace std;
template<typename T>
void selectionSort(T arr[], int n){
    for(int i = 0 ; i < n ; i ++){
        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;
        swap( arr[i] , arr[minIndex] );
    }
}
#endif //INC_04_INSERTION_SORT_SELECTIONSORT_H
~~~

