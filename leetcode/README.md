# TOP 100的问题

## 排序

```
#include <iostream>
#include <string>
#include<vector>
using namespace std;

class Solution {
public:
    void quikSort(vector<int>& nums, int left,int right) {
        if(left>=right){
            return;
        }
        int i=left,j=right;
        int flag=-1;
        while(i<j){
            if(flag==-1){
                if(nums[i]<nums[j]){
                    j--;
                    flag=-1;
                }
                else{
                    swap(nums[i],nums[j]);
                    i++;
                    flag=1;
                }
            }else{
                if(nums[j]>nums[i]){
                    i++;
                    flag=1;
                }
                else{
                    swap(nums[i],nums[j]);
                    j--;
                    flag=-1;
                }
            }
        }
        quikSort(nums,left,j-1);
        quikSort(nums,j+1,right);
    }


};

void merge(vector<int> &nums,int left,int mid,int right){
    vector<int> v1(nums.begin()+left,nums.begin()+mid);
    vector<int> v2(nums.begin()+mid+1,nums.begin()+right);
    int i=0,j=0,k=left,s1=v1.size(),s2=v2.size();
    while(i<s1&&j<s2){
        if(nums[i]<nums[j]){
            nums[k]=nums[i];
            k++;
        }else{
            nums[k]=nums[j];
            k++;
        }
    }
    if(i<s1){

    }
}

void mergeSort(vector<int>& nums,int left,int right){
    if(right>=left){
        return;
    }
    int mid=(right+left)/2;
    mergeSort(nums,left,mid);
    mergeSort(nums,mid+1,right);
    merge(nums,left,mid,right);
}
int main() {
    vector<int> v(100000000,0);
    Solution().quikSort(v,0,v.size()-1);
//    for(auto m:v){
//        cout<<m<<" ";
//    }

    return 0;
}
```

## 数组类

## 移除排序数组中的重复元素

链接：https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/

要求：不使用额外的空间，也就是说时间复杂度O（n）

leetcode一个大神的解法：

这个解法的思路很简单，就是判断前后两个数字是否是一样的，如果不一样，那么就要把它拷贝到前面。那么要拷贝到哪个位置，要看数字重复的次数，用count这个数字来表征。

~~~c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]=nums[i-1]){
                count++;
            }else{
                nums[i-count]=nums[i];
            }
        }
        return nums.size()-count;
    }
};

~~~

自己的思路：

用双指针来做这个事情。一个指向前面，一个指向后面。一旦后面那个指针对应的数字不同于其后面那个数字，那么就要将其进行拷贝到前面指针的位置，同时指针相应移动一位。

~~~c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=-1,j=0;
        while(j<nums.size()-1){
            if(nums[j]!=nums[j+1]){
                i++;
                nums[i]=nums[j+1];
            }else{
                j++;
            }
        }
        return i+1;
    }
};
~~~

当然，这一题还可以用set来解决。因为set中不会有重复数字。

## 数学类

判断一个数字是不是3的次方。

这一题可以使用递归的方法来做。

~~~c++
//使用递归的方案来做
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1){
            return true;
        }
        if(n==0||n%3!=0){
             return false;
        }else{
            return isPowerOfThree(n/3);
        }
        
    }
};
~~~

特别注意：n==0的情况。

# Easy

## Remove Duplicates from Sorted Array

Given a sorted array *nums*, remove the duplicates [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) such that each element appear only *once* and return the new length.

Do not allocate extra space for another array, you must do this by **modifying the input array in-place** with O(1) extra memory.

**Example 1:**

```
Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
```

**Example 2:**

```
Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
```



Solution

~~~c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]=nums[i-1]){
                count++;
            }else{
                nums[i-count]=nums[i];
            }
        }
        return nums.size()-count;
    }
};
~~~



Given an array, rotate the array to the right by *k* steps, where *k* is non-negative.

**Example 1:**

```
Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

**Example 2:**

```
Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

**Note:**

- Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
- Could you do it in-place with O(1) extra space?

方案一:暴力搜索

~~~c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp,prev;
        for(int i=0;i<k;i++){
            prev=nums[nums.size()-1];
            for(int j=0;j<nums.size();j++){
                temp = nums[j];
                nums[j] =prev;
                prev=temp;
            }
        }
    }
};
~~~

