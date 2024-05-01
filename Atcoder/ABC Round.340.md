---
tags:
  - 题解
  - atcoder
---
# A [Arithmetic Progression](https://atcoder.jp/contests/abc340/tasks/abc340_a)

## 题目描述
>打印首项为`a` ,末项小于等于`b`,公差为`c`的等差数列
## 解题思路
>签到题,`while`循环<font color=#008000>AC</font>此题

## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 1e17 + 50;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    int a, b, c;
    std::cin >> a >> b>> c;
    while(a <= b){
        std::cout << a << ' ';
        a += c;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int Lazy_boy_ = 1;
    // std::cin >> Lazy_boy_;
    while (Lazy_boy_--)
        solve();
    return 0;
}
```

# B [Append](https://atcoder.jp/contests/abc340/tasks/abc340_b)

## 题目描述
>有一个空序列`a`,和`n`次操作,每次操作会输入`t, x`:
>1. `t = 1`时,向序列`a`末尾插入`x`;
>2. `t = 2`时,查询倒数第`x`个的值,并输出;
## 解题思路
>题目中有插入和查询操作,我们可以直接使用`STL`中的`deque`模拟这两个操作.

## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 1e17 + 50;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    std::deque<int> q;
    int n, x, t;
    std::cin >> n;
    for(int i = 0 ; i < n ; i ++){
        std::cin >> t >> x;
        if(t == 1)
            q.push_back(x);
        else 
            std::cout << q[q.size() - x] << endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int Lazy_boy_ = 1;
    // std::cin >> Lazy_boy_;
    while (Lazy_boy_--)
        solve();
    return 0;
}
```
# C [Divide and Divide](https://atcoder.jp/contests/abc340/tasks/abc340_c)

## 题目描述
>给一个数`x`,如果这个数大于等于`2`就可以将这个数拆分为$\lfloor \frac{x}{2} \rfloor ,\lceil \frac{x}{2} \rceil$,并且花费为`x`
>问:分解到所有数小于`2`需要花费多少?
## 解题思路
>开始,我用`queue`模拟过程,感觉这个题还很简单,提交后`TLE`,卧槽, 怎么会啊,回头一想,`x`取很大的时候,回头一想,这`TM`不就是一个递归的题吗?
>我们需要记忆化递归,可以用`map`或者`unorder_map`来存储递归过的答案,这样可以省很多时间.
## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 1e17 + 50;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    int x;
    std::cin >> x;
    std::unordered_map<int, int> mp;
    auto calc = [&](auto sol, int x) {
        if (x == 1) return 0ll;
        if (mp.count(x)) return mp[x];
        return mp[x] = x + sol(sol, x / 2) + sol(sol, (x + 1) / 2);
    };
    std::cout << calc(calc, x) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int Lazy_boy_ = 1;
    // std::cin >> Lazy_boy_;
    while (Lazy_boy_--)
        solve();
    return 0;
}
```

# D [](https://atcoder.jp/contests/abc340/tasks/abc340_d)

## 题目描述
>
## 解题思路
>

## 参考代码
```cpp

```
