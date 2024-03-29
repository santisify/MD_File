# A [Wallet Exchange](https://codeforces.com/contest/1919/problem/A)

## 题目大意

> `Alice`有`a`个硬币,`Bob`有`b`个硬币,双方轮流进行以下操作:
> 1.与对方交换硬币,或者保留现有硬币.
> 2.取出一个硬币
> 无法进行操作的人判定为输,总是从`Alice`开始操作
> 问:哪位获得胜利

## 解题思路

> 我们可以把游戏看作是轮流取硬币,取得最后一个硬币的为胜利
> 那么我们就可以直接判断`a+b`奇偶性就可以得出答案.

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define fix(n) std::fixed << std::setprecision(n)
[[maybe_unused]]typedef std::pair<int, int> pii;
[[maybe_unused]]const int INF = 1e18 + 50;

void solve() {
    int a, b;
    std::cin >> a >> b;
    std::cout << ((a + b) % 2 ? "Alice" : "Bob") << endl;
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

# B [Plus-Minus Split](https://codeforces.com/contest/1919/problem/B)

## 题目大意

> 略

## 解题思路

> 简单看下样例就猜出来是`+`与`-`的差值的绝对值

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define fix(n) std::fixed << std::setprecision(n)
[[maybe_unused]]typedef std::pair<int, int> pii;
[[maybe_unused]]const int INF = 1e18 + 50;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int cnt1 = 0;
    for (auto i: s)
        cnt1 += (i == '+');
    std::cout << abs((n - cnt1) - cnt1) << endl;
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

# C [Grouping Increases](https://codeforces.com/contest/1919/problem/C)

## 题目大意

> ![image.png](assets/image.png)

## 解题思路

> 贪心

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define fix(n) std::fixed << std::setprecision(n)
[[maybe_unused]]typedef std::pair<int, int> pii;
[[maybe_unused]]const int INF = 1e18 + 50;

void solve() {
    int n, ans = 0;
    std::cin >> n;
    std::vector<int> a(n, 0ll);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::vector<int> A, B;
    A.push_back(INF), B.push_back(INF);
    for (int i = 0; i < n; i++) {
        int x = A.back(), y = B.back();
        if (x < y) {
            if (a[i] <= x)
                A.push_back(a[i]);
            else if (a[i] <= y)
                B.push_back(a[i]);
            else {
                A.push_back(a[i]);
                ans++;
            }
        } else {
            if (a[i] <= y)
                B.push_back(a[i]);
            else if (a[i] <= x)
                A.push_back(a[i]);
            else {
                B.push_back(a[i]);
                ans++;
            }
        }
    }
    std::cout << ans << endl;
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
