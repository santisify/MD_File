# A [Tricky Template](https://codeforces.com/contest/1922/problem/A)

## 题目描述

> 给一个数字`n`和三个长度为`n`的字符串 `a`,`b`,`c`。找一个模板使得字符串`a`,`b`匹配，而`c`不匹配,是否存在这样一个模板.
>
> 匹配的定义是:当模板字母为小写时,两个字符串字符相同,为大写时,两个字符不同,这样的两个字符串则匹配

## 解题思路

> 我们可以直接得出当`a`字符串和`b`字符串都不等于`c`字符串时,就存在这样一个模板使得满足题意

## 参考代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 1e18 + 50, pi = 3;
[[maybe_unused]]typedef std::pair<int, int> pii;

void solve() {
    int n;
    std::cin >> n;
    std::string a, b, c;
    std::cin >> a >> b >> c;
    for (int i = 0; i < n; i++)
        if (a[i] != c[i] && b[i] != c[i]) {
            std::cout << "YES" << endl;
            return;
        }
    std::cout << "NO" << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int Lazy_boy_ = 1;
    std::cin >> Lazy_boy_;
    while (Lazy_boy_--) solve();
    return 0;
}
```

# B [Forming Triangles](https://codeforces.com/contest/1922/problem/B)

## 题目描述

> 给定一个长度为`n`的一个数组`a`,对于`a[i]`来说,就是一个长度为`2^a[i]`的木棒,现在问:用这些木棒能组成多少个三角形.

## 解题思路

> 对于一个三角形来说,两边之和大于第三边,两边之差小于第三边,不可能存在两边之和等于第三边,那么我们就可以得到要组成一个三角形就至少需要两条边相等,第三边小于等于这两个边,那么这个问题就成了一个组合数问题
>
> 组合数用`C(cnt, m)`来表示,其中`cnt`为这个数的总数,`m`为我们需要选的个数;
> `cnt`可以用`map`来写,对数组去重,遍历一次数组,`s`表示比遍历到当前数字小的个数
> 即写成`ans += C(mp[a[i]], 3) + C(mp[a[i]], 2) * s`

## 参考代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 1e18 + 50, pi = 3;

int C(int n, int m) {
    if (n < m) return 0;
    int ans = 1;
    for (int i = 1; i <= m; i++)
        ans = ans * (n - m + i) / i;
    return ans;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n, 0ll);
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) std::cin >> a[i], mp[a[i]]++;
    std::sort(a.begin(), a.end());
    n = std::unique(a.begin(), a.end()) - a.begin();
    int ans = C(mp[a[0]], 3), s = 0;
    for (int i = 1; i < n; i++) {
        int t = mp[a[i]];
        s += mp[a[i - 1]];
        ans += C(t, 3) + C(t, 2) * s;
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

# C [Closest Cities](https://codeforces.com/contest/1922/problem/C)

## 题目描述

> 在`x`轴上有`n`个城市,其位置为`a[i]`,并且序列`a`按升序排列,保证每个城市只有一个最近的城市
> 若`i`的最近城市是`i+1`则花费`1`,否则花费`|a[i]-a[i+1]|`,现在有`q`次询问
> 问:每次询问城市`x`到城市`y`的最小花费.

## 解题思路

> 先分析一下`x<y`,我们只有一直向右走才会有最小花费,那就需要判断当前城市的最近城市是否为下一个城市.
> 由于是一直向右走,我么就可以用前缀和求解这个问题.
> 同理,`x>y`时,我们是从右向左走,可以用后缀和求解.

## 参考代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 1e18 + 50, pi = 3;

void solve() {
    int n, q;
    std::cin >> n;
    std::vector<int> a(n + 1, 0ll);
    auto s1 = a, s2 = a;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    s1[2] = 1;
    for (int i = 2; i < n; i++) {
        if (a[i] - a[i - 1] > a[i + 1] - a[i]) s1[i + 1] = s1[i] + 1;
        else s1[i + 1] = s1[i] + abs(a[i + 1] - a[i]);
    }
    s2[n - 1] = 1;
    for (int i = n - 1; i > 1; i--) {
        if (a[i] - a[i - 1] > a[i + 1] - a[i]) s2[i - 1] = s2[i] + abs(a[i] - a[i - 1]);
        else s2[i - 1] = s2[i] + 1;
    }
//    for (int i = 1; i <= n; i++)
//        std::cout << s1[i] << ' ';
//    std::cout << endl;
//    for (int i = 1; i <= n; i++)
//        std::cout << s2[i] << ' ';
    std::cout << endl;
    std::cin >> q;
    while (q--) {
        int x, y;
        std::cin >> x >> y;
        if (x < y)
            std::cout << s1[y] - s1[x] << endl;
        else
            std::cout << s2[y] - s2[x] << endl;
    }
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