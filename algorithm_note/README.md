# Leetcode笔记

## 动态规划

### 斐波那契数列

首先看一个斐波那契数的例子。

![1](E:\leetcode\Play-with-Algorithm-Interview\Note\pics\1.png)

斐波那契数可以用递归来做，但是递归会存在大量重复的计算，因此时间复杂度很高，是2的n次方，这非影响性能。

![2](E:\leetcode\Play-with-Algorithm-Interview\Note\pics\2.png)

可以通过一个办法来解决，就是用记忆化搜索的方法，也就是，如果计算过了，就保存起来，到时候直接调用就可以。

![3](E:\leetcode\Play-with-Algorithm-Interview\Note\pics\3.png)

递归方法是一个自上而下的解决问题的方式，也就是说，从大的问题开始解决，然后解决小的问题。递归方法很可能会遇到重复子问题，这样时间复杂度很高，也会大量浪费系统栈资源。可以通过记忆化的搜索方法降低时间复杂度。

**动态规划**则是自下而上的方法来解决问题。也就是将复杂问题转为若干简单的问题，简单问题先解决了，然后结果进行保存，复杂问题的解决可以用到这些简单问题的结果。这样，对于斐波那契数问题，时间复杂度就变成了o(n)级别。

![4](E:\leetcode\Play-with-Algorithm-Interview\Note\pics\4.png)

递归和动态规划的关系

![5](E:\leetcode\Play-with-Algorithm-Interview\Note\pics\5.png)



### 爬台阶问题

每次只能向上爬一个台阶，或者两个台阶，请问爬n阶台阶有几种爬法？
递归方法：要爬上n台阶，可以在n-1台阶的时候往上爬一步，或者在n-2台阶的时候往上爬二步两种方法，那如果知道n-1和n-2台阶的时候方法数，那加起来就可以了。
这个问题实际上就是斐波那契的问题。

![6](E:\leetcode\Play-with-Algorithm-Interview\Note\pics\6.png)

首先，这个问题可以转化为子问题来求解，因此是一个递归问题。

![7](E:\leetcode\Play-with-Algorithm-Interview\Note\pics\7.png)

同时它存在很多重叠子问题，因此可以使用记忆化搜索的方法。

![8](E:\leetcode\Play-with-Algorithm-Interview\Note\pics\8.png)

既然是一个递归问题，而且有很多重叠子问题，因此就可以使用动态规划的方法求解。

递归c++代码：

~~~c++
//代码运行超时
class Solution {
public:
    int climbStairs(int n) {
        return calcWays(n);
    }
    
    int calcWays(int n){
        if(n==1){
            return 1;
        }
        if (n==2){
            return 2;
        }
        return calcWays(n-1)+calcWays(n-2);
    }
};

~~~

记忆化搜索代码：

~~~c++
class Solution {
private:
    vector<int> memo;
public:
    int climbStairs(int n) {
        memo=vector<int>(n,-1);
        return calcWays(n);
    }
    
    int calcWays(int n){
        if(n==1){
            memo[0]=1;
        }
        if (n==2){
            memo[1]=2;
        }
        if(memo[n-1]==-1){
            memo[n-1]=calcWays(n-1)+calcWays(n-2);
        }
        return memo[n-1];
    }
};
~~~

动态规划代码

~~~c++
#include <iostream>
#include <vector>

using namespace std;

/// 70. Climbing Stairs
/// https://leetcode.com/problems/climbing-stairs/description/
/// 动态规划
/// 时间复杂度: O(n)
/// 空间复杂度: O(n)
class Solution {

public:
    int climbStairs(int n) {

        vector<int> memo(n + 1, -1);
        memo[0] = 1;
        memo[1] = 1;
        for(int i = 2 ; i <= n ; i ++)
            memo[i] = memo[i - 1] + memo[i - 2];
        return memo[n];
    }
    // int climbStairs(int n) {
    //     memo=vector<int>(n,-1);
    //     memo[0]=1;
    //     memo[1]=2;
    //     for(int i=2;i<n;i++){
    //         memo[i]=memo[i-1]+memo[i-2];
    //     }
    //     return memo[n-1];
    // }
};

int main() {

    cout << Solution().climbStairs(10) << endl;
    return 0;
}
~~~

三角形问题

![9](E:\leetcode\Play-with-Algorithm-Interview\Note\pics\9.png)

最小路径和

![10](E:\leetcode\Play-with-Algorithm-Interview\Note\pics\10.png)

### 发现重叠子问题

![11](E:\leetcode\Play-with-Algorithm-Interview\Note\pics\11.png)