# A [Brick Wall](https://codeforces.com/contest/1918/problem/A)

## 题目描述
>砖块大小为`1 * k`,砖块可以水平和竖直放置,
>现在,我们用这样的砖块砌一堵`n * m`的墙, 墙的稳定性为水平砖块数与垂直砖块数之差.
>问:最大稳定性是多少
## 解题思路
>  为了使墙的稳定性最高,我们可以让所有的砖块水平放置,且砖块的大小为`1*2`,这样墙的稳定性为
>  $$n \times (m / 2)$$
## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 1e16 + 50, MOD = 10007;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::cout << n * (m / 2) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int Lazy_boy_ = 1;
    std::cin >> Lazy_boy_;
    while (Lazy_boy_--)
        solve();
    return 0;
}
```

# B [Minimize Inversions](https://codeforces.com/contest/1918/problem/B)

## 题目描述
>长度为`n`的数组`a`和`b`,由于讨厌倒置($a_{i}<a_{j},i >j$)
>我们将调整顺序即:交换$a_i,a_j和b_i,b_j$
>以使倒置的数较少
## 解题思路
>我们可以直接对一个数组排序即可,这样就可以使一个数组没有倒置,使答案最小化.

## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 1e17 + 50;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    int n;
    std::cin >> n;
    std::vector<pii> a(n);
    for(int i = 0; i < n; i ++)
        std::cin >> a[i].first;
    for(int i = 0; i < n; i ++)
        std::cin >> a[i].second;
    std::sort(a.begin(), a.end());
    for(int i = 0 ; i < n ; i ++)
        std::cout << a[i].first << " \n"[i == n - 1];
    for(int i = 0 ; i < n ; i ++)
        std::cout << a[i].second << " \n"[i == n - 1];
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int Lazy_boy_ = 1;
    std::cin >> Lazy_boy_;
    while (Lazy_boy_--)
        solve();
    return 0;
}
```
# C [XOR-distance](https://codeforces.com/contest/1918/problem/C)

## 题目描述
>输入三个数`a,b,r`;
>$$求|(a \oplus x - (b \oplus x)|的最小值(0 \le x \le r))$$
## 解题思路
> 按位贪心
> 

## 参考代码
```cpp

```
