## 二、面试中的复杂度分析

### 时间复杂度自己的理解

时间复杂度自己的理解：

如果$f(n)=n^2+2n+3$ ，如果能够找到一个$g(n)$能使极限$lim_{n→0}f(n)/g(n)=0$，则时间复杂度为：$O(g(n))$ 。

### 递归算法的复杂度分析

主要考虑两种情况：

![1534766336050](pics/1534766336050.png)

多次调用的情况。

假设：

![1534767217227](pics/1534767217227.png)

时间复杂度分析：

![1534766812444](pics/1534766812444.png)

计算时间复杂度，就是计算总运算的数量。实际上只要计算每一层的节点数目就可以代表相应数字运行的次数。

归并排序的情况：

![1534768246694](pics/1534768246694.png)

### 均摊复杂度分析

典型例子，动态数组（vector）:

![1534768762293](pics/1534768762293.png)



![1534768780523](pics/1534768780523.png)

### 防止复杂度震荡

![1534768894289](pics/1534768894289.png)

![1534768901212](pics/1534768901212.png)

