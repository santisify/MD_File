# A [Problemsolving Log](https://codeforces.com/contest/1914/problem/A)

## 题目描述

> 给一个整数`n`,字符串`s`,字符串中`s[i]`表示第`i`分钟解决第`s[i]`题.
> 问题`A`需要`1`分钟解决,问题`B`需要`2`分钟解决,以此类推.
>
> 问:可以解决多少题?

## 解题思路

> 遍历字符串,统计问题`A -- Z`用了多少时间解决.
> 最后在遍历数组,判断问题`A -- Z`是否满足解决时间.

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> a(26, 0);
    for (auto i: s)
        a[i - 'A']++;
    int cnt = 0;
    for (int i = 0; i < 26; i++)
        if (a[i] >= i + 1)
            cnt++;
    std::cout << cnt << endl;
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

# B [Preparing for the Contest](https://codeforces.com/contest/1914/problem/B)

## 题目描述

> 给两个整数`n, k (0 <= k <= n - 1)`
> 问:打印出`a[i + 1] > a[i](0<= i < n - 1)`的次数等于`k`的方案.

## 解题思路

> 打个比方:
> `n == 6, k == 2`, 我们有这样一个数组`[1, 2, 3, 4, 5, 6]`
> 现在将数组重新排序,排序后要满足`a[i + 1] > a[i](0<= i < n - 1)`的次数等于`k`.
> 我们可以将数组后面`k + 1`个数放在前面,即`[4, 5, 6, 1, 2, 3]`
> 多举几个例子就可以发现上述规律.

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n, 0ll);
    std::iota(a.begin(), a.end(), 1ll);
    for (int i = n - k - 1; i < n; i++)
        std::cout << a[i] << " ";
    for (int i = n - k - 2; i >= 0; i--)
        std::cout << a[i] << " ";
    std::cout << endl;
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

# C [Quests](https://codeforces.com/contest/1914/problem/C)

## 题目描述

> 有`n`个任务,每个任务完成后对应两个值`a[i]`和`b[i]`,首次完成第`i`个任务时,可获得`a[i]`分,若此后再完成该任务可获得`b[i]`分
> 问:现在,可以完成`k`个任务,可获得的最大分数是多少?

## 解题思路

> 枚举走到哪一个位置，然后记录前面的b[i]最大值

## 代码

```cpp

#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]typedef std::pair<int, int> pii;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1, 0ll), b(n + 1, 0ll);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];
    int s = 0, ma = 0, ans = 0;
    for (int i = 0; i < std::min(n, k); i++) {
        s += a[i];
        ma = std::max(ma, b[i]);
        ans = std::max(ans, s + (k - i - 1) * ma);
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

# D [Three Activities](https://codeforces.com/contest/1914/problem/D)

## 题目描述

> 给出一个`n`,并且给出这`n`天参加三项活动的人数`a[i], b[i], c[i]`.
>
> 问:最多能有多少人参加这三项活动,并且参加这三项不在同一天.

## 解题思路

> 我们只需要模拟一下,但是这个模拟需要优化一下.

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]typedef std::pair<int, int> pii;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n, 0ll), b(n, 0ll), c(n, 0ll);
    for (int i = 0; i < n; i++)std::cin >> a[i];
    for (int i = 0; i < n; i++)std::cin >> b[i];
    for (int i = 0; i < n; i++)std::cin >> c[i];
    std::vector<int> x(n, 0ll);
    std::iota(x.begin(), x.end(), 0ll);
    auto y = x, z = x;
    std::sort(x.begin(), x.end(), [&](int aa, int bb) { return a[aa] > a[bb]; });
    std::sort(y.begin(), y.end(), [&](int aa, int bb) { return b[aa] > b[bb]; });
    std::sort(z.begin(), z.end(), [&](int aa, int bb) { return c[aa] > c[bb]; });
    int w = std::min({n, 100ll}), ans = 0ll;
    for (int i = 0; i < w; i++)
        for (int j = 0; j < w; j++)
            for (int k = 0; k < w; k++)
                if (x[i] != y[j] && x[i] != z[k] && y[j] != z[k])
                    ans = std::max(a[x[i]] + b[y[j]] + c[z[k]], ans);
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
