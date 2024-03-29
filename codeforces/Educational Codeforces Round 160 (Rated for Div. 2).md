# A [Rating Increas](https://codeforces.com/contest/1913/problem/A)

## 题目大意

> 给定一个数字,让我们拆分成两个数,这两个数满足以下条件:
>
> 1. `a < b`.
> 2. 两个数没有前缀`0`.
>
> 问:输出满足条件的数`a , b`.

## 解题思路

> 直接暴力循环这个数的位数次,若满足`a < b`,再判断两个数的位数和是否与拆分前相同.

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

void solve() {
    int n, cnt = 1, k = 0;
    std::cin >> n;
    int s = n;
    while (s) {
        k++;
        s /= 10;
    }
    int t = k;
    while (k--) {
        int w = n;
        int a = w / cnt, b = w % cnt;
        int x = a, y = b;
        int s1 = 0, s2 = 0;
        while (x) {
            s1++;
            x /= 10;
        }
        while (y) {
            s2++;
            y /= 10;
        }
        if (a < b && s1 + s2 == t) {
            std::cout << a << " " << b << endl;
            return;
        }
        cnt *= 10;
    }
    std::cout << -1 << endl;
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

---

# B [Swap and Delete](https://codeforces.com/contest/1913/problem/B)

## 题目大意

> 给一个`01`字符串`s`,现在有以下操作:
>
> 1. 交换`s[i],s[j]`,此操作花费为`0`.
> 2. 删除`s[i]`,此操作花费一个金币.
>
> 将修改后的字符串记录为`t`.
> 问:至少花费多少金币,使得`t[i] != s[i] (0 <= i <= t.size())`.

## 解题思路

> 我们可以记一下有多少个`0` 和多少个`1`,
> 然后我们遍历一次字符串,`check`当前`0`的个数是否大于`1`的总数和当前`1`的个数是否大于`0`的总数

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

void solve() {
    std::string s;
    std::cin >> s;
    int s0 = 0, s1 = 0;
    for (auto i: s)
        s0 += (i == '0'), s1 += (i == '1');
    int cnt0 = 0, cnt1 = 0, ans = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        cnt0 += (s[i] == '0'), cnt1 += (s[i] == '1');
        if (s0 >= cnt1 && s1 >= cnt0)
            ans = std::max(ans, i + 1);
    }
    std::cout << (int) s.size() - ans << endl;
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

# C [Game with Multiset](https://codeforces.com/contest/1913/problem/C)

## 题目大意

> 有两种查询类型:
>
> 1. `ADD x`,即在集合中添加`2^x`的元素.
> 2. `GET w`,即询问集合中的某子集之和,能否等于`w`.

## 解题思路

> 很显然,本题考查位运算,用数组模拟,其中`cnt[i]`表示集合中`2^i`的元素个数.

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> cnt(32, 0ll);
    auto calc = [&](int x) {
        for (int i = 31; i >= 0; i--) {
            int l = 0, r = cnt[i], s = 0;
            while (l <= r) {
                int mid = (l + r + 1) >> 1;
                if (mid * (1 << i) <= x)
                    s = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            x -= (1 << i) * s;
        }
        std::cout << (x == 0 ? "YES" : "NO") << endl;
    };
    while (n--) {
        int t, v;
        std::cin >> t >> v;
        if (t == 1)
            cnt[v]++;
        else
            calc(v);
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
