[传送门](https://ac.nowcoder.com/acm/contest/74362#question)
# A  [小红小紫替换](https://ac.nowcoder.com/acm/contest/74362/A)

## 解题思路
> 签到题,不用多bibi

## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 1e18 + 50;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    std::string s;
    std::cin >> s;
    if(s == "kou")
        std::cout << "yukari" << endl;
    else 
        std::cout << s << endl;
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

# B [小红的因子数](https://ac.nowcoder.com/acm/contest/74362/B)

## 题目描述
>[acwing](https://www.acwing.com)的算法基础课模板题[分解质因数](https://www.acwing.com/problem/content/869/)
## 解题思路
>可直接`acwing`上的讲解,顺便多学学数论

## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 1e18 + 50;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    std::set<int> s;
    int n;
    std::cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            s.insert(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n != 1)
        s.insert(n);
    std::cout << s.size() << endl;
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
# C [小红的字符串中值](https://ac.nowcoder.com/acm/contest/74362/C)

## 题目描述
>在字符串`s`中,让我们计算有多少个子字符串`t`是以字符`ch`为中间字符的.
## 解题思路
>我们可以贪心的看下一个字符串`ababc`,我们来找下这个字符串中以`b`为中间字符的子字符串有哪些:
>首先我们看第一个字符`b`可以得知有:字符串`aba`和`b`
>对于第二个字符`b`有:`abc`和`b`;
>这样就可以看出满足条件的子串数量与该字符在字符串的那个位置有关
>那么就可以推出单个字符的子串数量是:$min(i, n - i - 1) + 1(0 \le i \le n - 1)$

## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 1e18 + 50;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    int n, ans = 0, cnt = 0;
    char ch;
    std::cin >> n >> ch;
    std::string s;
    std::cin >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == ch)
            ans += std::min(i, n - i - 1), cnt ++;
    std::cout << ans + cnt << endl;
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

# D [小红数组操作]()

## 题目描述
>
## 解题思路
>由于链表较为麻烦,可以使用`map`进行模拟

## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 1e9 + 1;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    std::map<int, int> l, r;
    int q;
    std::cin >> q;
    l[INF] = 0;
    r[0] = INF;
    while (q--) {
        int t, x, y;
        std::cin >> t;
        if (t == 1) {
            std::cin >> x >> y;
            int rr = r[y];
            l[x] = y, r[x] = rr;
            r[y] = x, l[rr] = x;
        } else {
            std::cin >> x;
            int ll = l[x], rr = r[x];
            r[ll] = rr;
            l[rr] = ll;
        }
    }
    int w = 0, cnt = 0;
    while (r[w] != INF) {
        w = r[w];
        cnt++;
    }
    std::cout << cnt << endl;
    w = 0;
    while (r[w] != INF) {
        w = r[w];
        std::cout << w << ' ';
    }
    std::cout << endl;
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
