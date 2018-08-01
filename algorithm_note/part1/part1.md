# Leetcode 笔记

## 一、数组

数组看上去简单，实际上在很多场景都有应用。

比如，在排序中：选择排序，插入排序，归并排序，快速排序。

查找：二分查找

数据结构中的底层实现：栈，队列，堆

### 1. 二分查找

二分查找条件：有序数列

二分查找需要定义好变量，明确边界。

代码如下：

~~~c++
#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include "util.h"

using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target){

    int l = 0, r = n - 1; // 在[l...r]的范围里寻找target
    while(l <= r){    // 当 l == r时,区间[l...r]依然是有效的
        int mid = l + (r - l) / 2;
        if(arr[mid] == target) return mid;
        if(target > arr[mid])
            l = mid + 1;  // target在[mid+1...r]中; [l...mid]一定没有target
        else    // target < arr[mid]
            r = mid - 1;  // target在[l...mid-1]中; [mid...r]一定没有target
    }

    return -1;
}

int main() {

    int n = pow(10, 7);
    int* data = MyUtil::generateOrderedArray(n);

    clock_t startTime = clock();
    for(int i = 0 ; i < n ; i ++)
        assert(i == binarySearch(data, n, i));
    clock_t endTime = clock();

    cout << "Binary Search test complete." << endl;
    cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

    return 0;
}
~~~

### 2. move zeros

![1](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\1.png)

这个题目有好几个思路：

思路1：将非零元素拷贝的一个新的数组中，完了之后，将这个数组拷贝回原数组，并且末尾的元素赋值为0。

~~~c++
#include <iostream>
#include <vector>

using namespace std;

// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/
// 时间复杂度: O(n)
// 空间复杂度: O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        vector<int> nonZeroElements;

        // 将vec中所有非0元素放入nonZeroElements中
        for(int i = 0 ; i < nums.size() ; i ++)
            if(nums[i])
                nonZeroElements.push_back(nums[i]);

        // 将nonZeroElements中的所有元素依次放入到nums开始的位置
        for(int i = 0 ; i < nonZeroElements.size() ; i ++)
            nums[i] = nonZeroElements[i];

        // 将nums剩余的位置放置为0
        for(int i = nonZeroElements.size() ; i < nums.size() ; i ++)
            nums[i] = 0;
    }
};

int main() {

    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));

    Solution().moveZeroes(vec);

    for(int i = 0 ; i < vec.size() ; i ++)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}
~~~

思路2：原地赋值。

遍历数组，如果元素非零，赋值给索引k的位置，同时k++。如果为零，则不用赋值，同时k也不做操作。宗旨就是，遍历快的那个元素，遇到零了就不要去做什么动作。

~~~c++
#include <iostream>
#include <vector>

using namespace std;

// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/
//
// 原地(in place)解决该问题
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int k = 0; // nums中, [0...k)的元素均为非0元素

        // 遍历到第i个元素后,保证[0...i]中所有非0元素
        // 都按照顺序排列在[0...k)中
        for(int i = 0 ; i < nums.size() ; i ++)
            if(nums[i])
                nums[k++] = nums[i];

        // 将nums剩余的位置放置为0
        for(int i = k ; i < nums.size() ; i ++)
            nums[i] = 0;
    }
};

int main() {

    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    Solution().moveZeroes(vec);

    for(int i = 0 ; i < vec.size() ; i ++)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}
~~~

思路3：原地交换

将零元素和非零元素进行交换位置。注意一点：遍历快的那个索引，如果遇到0，遍历慢的那个索引就不需要加1。

~~~c++
#include <iostream>
#include <vector>

using namespace std;

// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/
//
// 原地(in place)解决该问题
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int k = 0; // nums中, [0...k)的元素均为非0元素

        // 遍历到第i个元素后,保证[0...i]中所有非0元素
        // 都按照顺序排列在[0...k)中
        // 同时, [k...i] 为 0
        for(int i = 0 ; i < nums.size() ; i ++)
            if(nums[i])
                swap(nums[k++] , nums[i]);

    }
};

int main() {

    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    Solution().moveZeroes(vec);

    for(int i = 0 ; i < vec.size() ; i ++)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}
~~~

### Sort colors

![2](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\2.png)

看到这个题目，如果没有思路，可以直接使用常规的排序方法。

但是这一题有特殊条件的，因此，一定可以有更好的解法。

思路1：使用统计的方法，分别统计出三个数字的总数，然后将原数组赋值就可以了。

~~~c++
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/description/
//
// 计数排序的思路
// 对整个数组遍历了两遍
// 时间复杂度: O(n)
// 空间复杂度: O(k), k为元素的取值范围
class Solution {
public:
    void sortColors(vector<int> &nums) {

        int count[3] = {0};    // 存放0, 1, 2三个元素的频率
        for(int i = 0 ; i < nums.size() ; i ++){
            assert(nums[i] >= 0 && nums[i] <= 2);
            count[nums[i]] ++;
        }

        int index = 0;
        for(int i = 0 ; i < count[0] ; i ++)
            nums[index++] = 0;
        for(int i = 0 ; i < count[1] ; i ++)
            nums[index++] = 1;
        for(int i = 0 ; i < count[2] ; i ++)
            nums[index++] = 2;

        // 小练习: 自学编写计数排序算法
    }
};

int main() {

    int nums[] = {2, 2, 2, 1, 1, 0};
    vector<int> vec = vector<int>(nums, nums + sizeof(nums)/sizeof(int));

    Solution().sortColors(vec);
    for(int i = 0 ; i < vec.size() ; i ++)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}

~~~

通过思路1能够解决问题，但是假设我们想只遍历一遍，需要怎么做？

思路2：三路快排。



### 对撞指针--双索引技术

Two sum

![3](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\3.png)

注意条件：1. 有序。2. 返回两个元素。

思路1：暴力解法，双层遍历。O(n2)

思路2：考虑到数组是有序的，对i个元素，剩下元素通过二分查找。O(nlogn)

![4](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\4.png)

思路3：由于有序，考虑使用指针对撞的方法。O(n)

其他的题目：

![5](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\5.png)

![6](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\6.png)

![7](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\7.png)

![8](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\8.png)

## 滑动窗口

![9](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\9.png)





## 二、查找问题

### 1. 什么是查找问题

查找问题可以分为两类：

1. 查找有无，元素‘a’是否存在。对应数据结构为set，集合。

2. 查找对应关系（键值对应），元素‘a’出现了多少次？对应的数据结构为map，字典。

### 2. set和map的常用函数

set和map在很多语言的标准库中都有，它们屏蔽了实现细节。不过我们要知道这些数据结构是怎么用的。

set和map的常见操作包括：

- insert：插入一个元素
- find：查找一个元素是否存在
- erase：清除元素
- change（map），改变键对应的值

### 3. 面试题：Intersection of two arrays

![10](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\10.png)

使用set解决：

思路1（自己的思路），将nums1放入vector中，对于nums2中的每个元素都在nums1中进行查找，找到就放到set中。

~~~c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //set<int> record(nums1.begin(),nums1.end());
        set<int> result;
        for(int i=0;i<nums2.size();i++){
            if(find(nums1.begin(),nums1.end(),nums2[i])!=nums1.end()){
                result.insert(nums2[i]);
            }
        }
        return vector<int>(result.begin(),result.end());

    }
};
~~~



思路2，将nums1放入set中，对于nums2中的每个元素都在nums1中进行查找，如果找到了就放到set中。

实现代码1：

~~~c++
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/description/
// 时间复杂度: O(nlogn)
// 空间复杂度: O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> record;
        for( int i = 0 ; i < nums1.size() ; i ++ )
            record.insert(nums1[i]);

        set<int> resultSet;
        for( int i = 0 ; i < nums2.size() ; i ++ )
            if(record.find(nums2[i]) != record.end())
                resultSet.insert(nums2[i]);

        vector<int> resultVector;
        for(set<int>::iterator iter = resultSet.begin(); iter != resultSet.end(); iter ++ )
            resultVector.push_back(*iter);

        return resultVector;
    }
};

int main() {

    int nums1[] = {1, 2, 2, 1};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));

    int nums2[] = {2, 2};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));

    vector<int> res = Solution().intersection(vec1, vec2);
    for(int i = 0 ; i < res.size() ; i ++ )
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
~~~

实现代码2：

~~~c++
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/description/
// 时间复杂度: O(nlogn)
// 空间复杂度: O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> record(nums1.begin(), nums1.end());

        set<int> resultSet;
        for( int i = 0 ; i < nums2.size() ; i ++ )
            if( record.find(nums2[i]) != record.end() )
                resultSet.insert( nums2[i] );

        return vector<int>(resultSet.begin(), resultSet.end());
    }
};

int main() {

    int nums1[] = {1, 2, 2, 1};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));

    int nums2[] = {2, 2};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));

    vector<int> res = Solution().intersection(vec1, vec2);
    for(int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}
~~~

### 4. 面试题：Intersection of two arrays II

需要特别的注意，在c++中，map的值默认情况下是0？所以要特别注意这一点。否则很可能会出错。

使用map解决：



### 4. set和map不同的底层实现

普通数组，就最简单的那种数组。插入一个元素直接在尾巴加。查找需要遍历数组，删除也要移动数组。

顺序数组，就是数组的数字都有顺序。插入一个元素需要遍历数组进行比较。查找数组可以用二分查找，复杂度为log(n)，删除元素需要移动。

二分搜索树，插入，查找和删除的时间复杂度都是log(n)

哈希表：哈希表的插入查找删除的时间复杂度都是O(1)，但是哈希表的缺点是没有顺序。

![11](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\11.png)

数据的顺序性有很多好处：

![12](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\12.png)

其他面试题

![15](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\15.png)

![16](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\16.png)

![17](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\17.png)

![18](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\18.png)

![19](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\19.png)

![20](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\20.png)

![21](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\21.png)

![22](E:\leetcode\Play-with-Algorithm-Interview\Note\part1\pics\22.png)





### 5. 一个使用查找表的经典问题

思路：

1. 暴力解法，时间复杂度O(n2)
2. 排序后，使用双指针对撞，O(nlog(n))+O(n)=O(nlog(n))，问题是这样需要储存相应的索引。
3. 将元素放入查找表。之后对于每个元素a，查找target-a是否存在。





