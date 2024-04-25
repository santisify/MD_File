# A [Past ABCs](https://atcoder.jp/contests/abc350/tasks/abc350_a)

## 题目描述
> 给定字符串 $s$ ,若字符串后三个数字为在区间$[001,315] \cup [316,349]$,那么输出 $Yes$ ,否则输出 $No$
## 参考代码
```cpp
#include<bits/stdc++.h>

#define int long long
#define endl '\n'
#define pii std::pair<int ,int>
#define fix(x) std::fixed << std::setprecision(x)
const int inf = 1e17 + 50, MAX_N = 3e6 + 50;

void solve() {
    std::string s;
    std::cin >> s;
    int n = (s[3] - '0') * 100 + (s[4] - '0') * 10 + (s[5] - '0');
    if(n == 316 || n >= 350 || n < 1) {
        std::cout << "No" << endl;
    }else {
        std::cout << "Yes" << endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int TT = 1;
    // std::cin >> TT;
    while (TT--) solve();
    return 0;
}
```

# B [Dentist Aoki](https://atcoder.jp/contests/abc350/tasks/abc350_b)

## 题目描述
> 
## 解题思路
>

## 参考代码
```cpp

```
# C

## 题目描述
>
## 解题思路
>

## 参考代码
```cpp

```

# D

## 题目描述
>
## 解题思路
>

## 参考代码
```cpp

```
