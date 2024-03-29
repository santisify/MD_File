# A [Capitalized?](https://atcoder.jp/contests/abc338/tasks/abc338_a)

## 题目描述
> 给定一个字符串`s`, 让我们判断是否满足首字母大写,其他字母小写的规则.

## 解题思路
> 直接用库函数`islower()`和`isupper()`模拟一下

## 参考代码
```cpp
#include <bits/stdc++.h>

//#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 2e18 + 50, MOD = 10007;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    std::string s;
    std::cin >> s;
    if (islower(s[0])) {
        std::cout << "No\n";
        return;
    }
    for (int i = 1; i < s.size(); i++)
        if (isupper(s[i])) {
            std::cout << "No\n";
            return;
        }

    std::cout << "Yes\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int Lazy_boy_ = 1;
//    std::cin >> Lazy_boy_;
    while (Lazy_boy_--)
        solve();
    return 0;
}
```
****
# B [Frequency](https://atcoder.jp/contests/abc338/tasks/abc338_b)
## 题目描述
> 给定一字符串`s`, 输出出现次数最多字符,若有多个输出字典序较小的.

## 解题思路
> 我们可以用数据结构`map`来存储,并记录最大的数.
> 由于`map`会自动将键按从小到大排序,那么我们就只需要遍历一次`map`的数据,当遍历到次数与最大值相同时,直接输出字符即可.
> 同样,用其他的方法计数也可行

## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 2e18 + 50, MOD = 10007;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    std::string s;
    std::cin >> s;
    int ma = 0;
    std::map<char, int> mp;
    for (auto i: s)
        mp[i]++, ma = std::max(ma, mp[i]);
    for (auto i: mp) {
        if (i.second == ma) {
            std::cout << i.first << endl;
            return;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int Lazy_boy_ = 1;
//    std::cin >> Lazy_boy_;
    while (Lazy_boy_--)
        solve();
    return 0;
}
```

# C [Leftover Recipes](https://atcoder.jp/contests/abc338/tasks/abc338_c)
## 题目描述
> 我们现在有`n`中配料,分别有$q_i$, 我们需要完成两种菜,这两个菜所用的配料分别$a_i,b_i$
> 问:我们最多能做多少个菜?

## 解题思路
> 假设我们做`x`个`A`菜,`y`个`B`菜,所花费的各个材料为$a_{i}*x + b_i*y$,由于`n`的数据范围较小,我们可以直接暴力循环$x\le10^6$ ,然后判断下$p_i<a_i*x$和$b_i$就行了
## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 2e18 + 50, MOD = 10007;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> q(n);
    auto a = q, b = q;
    for (int i = 0; i < n; i++) std::cin >> q[i];
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n; i++) std::cin >> b[i];
    int ans = 0;
    for (int x = 0; x <= 1e6; x++){
        int y = INF;
        for(int i = 0; i < n; i ++){
            if(q[i] < 1ll * a[i] * x)
                y = -INF;
            else if(b[i] > 0)
                y = std::min(y, (q[i] - a[i] * x) / b[i]);
        }
        ans = std::max(ans, x + y);
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int Lazy_boy_ = 1;
//    std::cin >> Lazy_boy_;
    while (Lazy_boy_--)
        solve();
    return 0;
}
```