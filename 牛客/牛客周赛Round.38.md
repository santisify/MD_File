---
tags:
  - 题解
  - acnowcoder
---
# A [小红的正整数自增](https://ac.nowcoder.com/acm/contest/78292/A)
## 题目描述
> 输入一个数`n`,输出需要加多少个`1`才能将个位数变为`1`
## 解题思路
>用`10`减去个位数模`10`即可.

## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define fix(n) std::fixed << std::setprecision(n)
[[maybe_unused]] const int inf = 1e17 + 50, MOD = 1e9 + 7;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    int x;
    std::cin >> x;
    std::cout << (10 - (x % 10)) % 10 << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int TT = 1;
//    std::cin >> TT;
    while (TT--)solve();
    return 0;
}
```

# B [小红的抛弃后缀](https://ac.nowcoder.com/acm/contest/78292/B)

## 题目描述
>给一个数, 输出有几种去除后缀后,剩余的是`9`的倍数.
## 解题思路
>模拟下即可,但数据范围为$10^{100000}$,所以需要输入字符串.

## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define fix(n) std::fixed << std::setprecision(n)
[[maybe_unused]] const int inf = 1e17 + 50, MOD = 1e9 + 7;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    std::string s;
    std::cin >> s;
    int ans = 0, t = 0;
    for (auto i: s) {
        t += i - '0';
    }
    if (t % 9 == 0) ans++;
    for (int i = s.size() - 1; i > 0; i--) {
        t -= s[i] - '0';
        if (t % 9 == 0) ans++;
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int TT = 1;
//    std::cin >> TT;
    while (TT--)solve();
    return 0;
}
```
# C [小红的字符串构造](https://ac.nowcoder.com/acm/contest/78292/C)

## 题目描述
>构造一个长度等于`n`,并且长度大于`1`的回文子串个数等于`k`
## 解题思路
>根据推导:
>1. 两个`a`,一个回文串
>2. 三个`a`,三个回文串(两个`aa`, 一个`aaa`)
>3. 四个`a`,六个回文串(三个`aa`, 两个`aaa`, 一个`aaaa`)
>以此类推可得知:`m`个相同字符可构成$m*(m - 1) / 2$个回文串, 同时,会占用`m`个位置
>但由于数据范围较大,不可能用不同的字符,所以有些字符可以间隔出现
>这里,我将出现的回文字符串由`a,b,c`组成,单个出现的由`x,y,z`组成.
>构成过程直接模拟一下就可以了

## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define fix(n) std::fixed << std::setprecision(n)
[[maybe_unused]] const int inf = 1e17 + 50, MOD = 1e9 + 7;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    int n, k;
    std::string s;
    std::cin >> n >> k;
    {
        char c = 'a';
        while (k) {
            int m = 1;
            while (m * (m + 1) / 2 <= k) m++;
            k -= m * (m - 1) / 2;
            while (m--) s += c;
            c++;
            if (c > 'c') c = 'a';
        }
        c = 'x';
        while (s.size() < n) {
            s += c;
            c++;
            if (c > 'z')c = 'x';
        }
    }
    std::cout << s << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int TT = 1;
//    std::cin >> TT;
    while (TT--)solve();
    return 0;
}
```

# D [小红的平滑值插值](https://ac.nowcoder.com/acm/contest/78292/D)

## 题目描述
> 一个数组`a`,现在向数组中插入一个元素（可进行多次）,现在需要最少操作使得$max_{i=1}^{n-1}|a_{i+1}- a_{i}|$  的值恰好等于`k`
## 解题思路
>首先举个样例：
>5 2
>1 4 5 1 6
>首先$a_1$与$a_2$之间肯定需要插入一个数$(4 - 1 = 3> 2)$，那么就需要插入2 或者3使得其达到要求。
>其次就是$a_4,a_5$，差值$t=6-1=5$, 明显需要插入两个数，
>于是我们可以发现，当差值`t`大于`k`时，我们就需要插入$t / k$个数，当然，还有一个情况
>当$k=2$时, 对于1和5来说，就只需要插入一个数字，所以还要判断差值是否能被`k`整除。

## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define fix(n) std::fixed << std::setprecision(n)
[[maybe_unused]] const int inf = 1e17 + 50, MOD = 1e9 + 7;
[[maybe_unused]] typedef std::pair<int, int> pii;

template<typename T = int>
std::vector<int> readVector(int n) {
    std::vector<T> a(n);
    for (T &x: a) std::cin >> x;
    return a;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    {
        int res = 0;
        bool f = false;
        auto a = readVector(n);
        for (int i = 1; i < n; i++) {
            int d = std::abs(a[i] - a[i - 1]);
            if (d >= k) {
                f = true;
                res += d / k;
                if (d % k == 0 && d > 0) res--;
            }
        }
        if (!f) res = 1;
        std::cout << res << endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int TT = 1;
//    std::cin >> TT;
    while (TT--)solve();
    return 0;
}
```

# E [小苯的等比数列](https://ac.nowcoder.com/acm/contest/78292/E)

## 题目描述
>
## 解题思路
>

## 参考代码
```cpp

```