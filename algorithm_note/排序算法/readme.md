---
typora-copy-images-to: pics
---

# 排序算法

## O(n2)排序算法

### 为什么要学习O(n2)的排序算法

![1535252055160](pics/1535252055160.png)

### 选择排序

简单选择排序是最简单直观的一种算法，基本思想为每一趟从待排序的数据元素中选择最小（或最大）的一个元素作为首元素，直到所有元素排完为止，简单选择排序是不稳定排序。

选择排序：每次都遍历数组，找出最小的，和最前面未排序的数字对换位置。不断重复就可以了。

选择排序的意思？选择最小的放在前面？

~~~c++
#include <iostream>
#include <algorithm>

using namespace std;

void selectionSort(int arr[], int n){

    for(int i = 0 ; i < n ; i ++){
        // 寻找[i, n)区间里的最小值
        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;
		//注意使用swap的时候需要#include<algorithm>
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

### 插入排序

![1024555-20161126000335346-416319390](pics/1024555-20161126000335346-416319390.png)

从头开始遍历，对于某个元素，往前面移动。

~~~c++
//优化过后的程序
template<typename T>
void insertionSort(T arr[], int n){

    for( int i = 1 ; i < n ; i ++ ) {
        T e = arr[i];
        int j; // j保存元素e应该插入的位置
        for (j = i; j > 0 && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }

    return;
}

//自己写的程序
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
void insertSort(int a[],int n) {
	for (int i=0;i < n;i++) {
		for (int j = 0;j < i;j++) {
			if (a[i ] < a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}
int main() {
	int test[] = { 2,5,2,2,9 };
	insertSort(test, 5);
	for (int i = 0;i < 5;i++) {
		cout << test[i] << " ";
	}

}
~~~

### 冒泡排序

冒泡排序的基本思想是，对相邻的元素进行两两比较，顺序相反则进行交换，这样，每一趟会将最小或最大的元素“浮”到顶端，最终达到完全有序。

![1024555-20161126001352300-2027386210](pics/1024555-20161126001352300-2027386210.png)

~~~c++
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
void bubbleSort(int a[],int n) {
	for (int j = n-1;j > 0;j--) {
		for (int i = 0;i < j;i++) {
			if (a[i + 1] < a[i]) {
				swap(a[i + 1], a[i]);
			}
		}
	}
}
int main() {
	int test[] = { 2,5,2,2,9 };
	bubbleSort(test, 5);
	for (int i = 0;i < 5;i++) {
		cout << test[i] << " ";
	}

}
~~~

## O(nlogn)算法

### 归并排序

特点：多了O(n)的空间。

归并排序（MERGE-SORT）是利用**归并**的思想实现的排序方法，该算法采用经典的**分治**（divide-and-conquer）策略（分治法将问题**分**(divide)成一些小的问题然后递归求解，而**治(conquer)**的阶段则将分的阶段得到的各答案"修补"在一起，即分而治之)。

![1024555-20161218163120151-452283750](pics/1024555-20161218163120151-452283750.png)

　可以看到这种结构很像一棵完全二叉树，本文的归并排序我们采用递归去实现（也可采用迭代的方式去实现）。**分**阶段可以理解为就是递归拆分子序列的过程，递归深度为log2n。

再来看看**治**阶段，我们需要将两个已经有序的子序列合并成一个有序序列，比如上图中的最后一次合并，要将[4,5,7,8]和[1,2,3,6]两个已经有序的子序列，合并为最终序列[1,2,3,4,5,6,7,8]，来看下实现步骤。

![1024555-20161218194508761-468169540](pics/1024555-20161218194508761-468169540.png)

归并排序是稳定排序，它也是一种十分高效的排序，能利用完全二叉树特性的排序一般性能都不会太差。java中Arrays.sort()采用了一种名为TimSort的排序算法，就是归并排序的优化版本。从上文的图中可看出，每次合并操作的平均时间复杂度为O(n)，而完全二叉树的深度为|log2n|。总的平均时间复杂度为O(nlogn)。而且，归并排序的最好，最坏，平均时间复杂度均为O(nlogn)。

~~~c++
#include <iostream>
#include <algorithm>
#include "InsertionSort.h"
using namespace std;
// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename  T>
void __merge(T arr[], int l, int mid, int r){

    //* VS不支持动态长度数组, 即不能使用 T aux[r-l+1]的方式申请aux的空间
    //* 使用VS的同学, 请使用new的方式申请aux空间
    //* 使用new申请空间, 不要忘了在__merge函数的最后, delete掉申请的空间:)
    T aux[r-l+1];
    //T *aux = new T[r-l+1];

    for( int i = l ; i <= r; i ++ )
        aux[i-l] = arr[i];

    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
    int i = l, j = mid+1;
    for( int k = l ; k <= r; k ++ ){

        if( i > mid ){  // 如果左半部分元素已经全部处理完毕
            arr[k] = aux[j-l]; j ++;
        }
        else if( j > r ){  // 如果右半部分元素已经全部处理完毕
            arr[k] = aux[i-l]; i ++;
        }
        else if( aux[i-l] < aux[j-l] ) {  // 左半部分所指元素 < 右半部分所指元素
            arr[k] = aux[i-l]; i ++;
        }
        else{  // 左半部分所指元素 >= 右半部分所指元素
            arr[k] = aux[j-l]; j ++;
        }
    }

    //delete[] aux;
}

// 使用优化的归并排序算法, 对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r){

    // 对于小规模数组, 使用插入排序
    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

    int mid = (l+r)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);

    // 对于arr[mid] <= arr[mid+1]的情况,不进行merge
    // 对于近乎有序的数组非常有效,但是对于一般情况,有一定的性能损失
    if( arr[mid] > arr[mid+1] )
        __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n){

    __mergeSort( arr , 0 , n-1 );
}
~~~

网络上找的代码：

~~~c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
/*该函数将数组下标范围[l1,r1]和[l2,r2]的有序序列合并成一个有序序列*/
void merge(vector<int>& nums, int l1, int r1, int l2, int r2 ) {
	int i = l1;                                               //左半部分起始位置
	int j = l2;                                               //右半部分起始位置
	int n = (r1 - l1 + 1) + (r2 - l2 + 1);                    //要合并的元素个数
	vector<int> temp(n);                                      //辅助数组
	int k = 0;	                                          //辅助数组其起始位置
	while (i <= r1&&j <= r2) {                                //挑选两部分中最小的元素放入辅助数组中
		if (nums[i] < nums[j])
			temp[k++] = nums[i++];
		else
			temp[k++] = nums[j++];
	}
	//如果还有剩余，直接放入到辅助数组中
	while (i <= r1)
		temp[k++] = nums[i++];
	while (j <= r2)
		temp[k++] = nums[j++];
	//更新原始数组元素
	for (int i = 0; i < n;i++)
	{
		nums[l1 + i] = temp[i];
	}
}
 
/*二路归并排序（递归实现）*/
void MergeSort(vector<int>& nums,int start, int end) {
	if (start < end) {
		int mid = (start + end) >> 1;				//分割序列
		MergeSort(nums, start, mid);				//对序列左半部分进行规并排序
		MergeSort(nums, mid + 1, end);				//对序列右半部分进行规并排序
		merge(nums, start, mid, mid + 1, end);                  //合并已经有序的两个序列
	}
}
 
/*二路归并排序（迭代实现）*/
void MergeSort1(vector<int>& nums, int start, int end)
{
	int n = nums.size();
	if (start < end) {
		//step为组内元素个数，step/2为左子区间元素个数
		for (int step = 2; step/2 <n; step *= 2) {
			//每step个元素一组，组内前step/2和后step/2个元素进行合并
			for (int i = 0; i < n; i += step) {
				int mid = i + step / 2 - 1;					//左子区间元素个数为step/2
				if(mid+1<n)							//右子区间存在元素个数则合并
					//左子区间为[i,mid]，右子区间为[mid+1, min(i+step-1, n-1)]
					merge(nums, i, mid, mid + 1, min(i + step - 1, n-1));
			}
		}
	}
}
 
int main() {
	vector<int> nums{ 1,4,3,2,5,6,3 };
	MergeSort(nums,0,6);
//	MergeSort1(nums, 0, 6);
	for (auto x : nums)
		cout << x << " ";
	cout << endl;
	return 0;
}

~~~

自己写的，有bug，需要进一步查找。

~~~c++
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
void Merge(vector<int> &nums, int l, int mid, int r) {
	int *temp = new int[r-l+1];
	for (int i = l;i <=r;i++) {
		temp[i-l] = nums[i];
		//cout << temp[i];
	}
	//int *temp= new int[r-l+1];
	int i = l;
	int j = mid + 1;
	for (int k = l;k <= r;k++) {
		if (i > mid) {
			nums[k] = temp[j- l];
			j++;
		}
		else if (j > r) {
			nums[k] = temp[i - l];
			i++;
		}else if (nums[i-l] < nums[j - l]) {
			nums[k] = temp[i-l];
			i++;
		}
		else{
			nums[k] = temp[j - l];
			j++;
		}
		
	}
	delete[]temp;
}
void MergeSort(vector<int>& nums, int l, int r) {
	if (l <r) {
		int mid = (l + r) / 2;
		MergeSort(nums, l, mid);
		MergeSort(nums, mid + 1, r);
		Merge(nums, l, mid, r);
	}
	
}

void mergesort(vector<int> &nums) {
	MergeSort(nums, 0, nums.size() - 1);
}


int main() {
	vector<int> nums={ 1,4,3,2,5,6,3 };
	mergesort(nums);
	//	MergeSort1(nums, 0, 7);
	for (int i = 0;i < 7;i++) {
		cout << nums[i] << " ";
	}
	return 0;

}
~~~

### 快速排序

https://blog.csdn.net/m0_37752084/article/details/80147989

### 快排

~~~c++
//
// Created by liuyubobobo on 4/25/17.
//

#ifndef CHAPTER_03_COMPLETED_CODE_QUICKSORT_H
#define CHAPTER_03_COMPLETED_CODE_QUICKSORT_H

#include <iostream>
#include <algorithm>
#include "InsertionSort.h"

using namespace std;

// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int _partition(T arr[], int l, int r){

    // 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
    swap( arr[l] , arr[rand()%(r-l+1)+l] );

    T v = arr[l];
    int j = l;
    for( int i = l + 1 ; i <= r ; i ++ )
        if( arr[i] < v ){
            j ++;
            swap( arr[j] , arr[i] );
        }

    swap( arr[l] , arr[j]);

    return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void _quickSort(T arr[], int l, int r){

    // 对于小规模数组, 使用插入排序进行优化
    if( r - l <= 15 ){
        insertionSort(arr,l,r);
        return;
    }

    int p = _partition(arr, l, r);
    _quickSort(arr, l, p-1 );
    _quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n){

    srand(time(NULL));
    _quickSort(arr, 0, n-1);
}

#endif //CHAPTER_03_COMPLETED_CODE_QUICKSORT_H

~~~



### 双路快排

### 随机快排

### 三路快排

