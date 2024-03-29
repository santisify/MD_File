# A [Forked!](https://codeforces.com/contest/1904/problem/A)

## 题目大意

> 给定王后和国王的位置, 马可以先朝一个方向走`a`步,再朝另一个方向走`b`步
> 问:马有多少个位置可以同时走到皇后和国王

## 解题思路

> 就无脑遍历一下马能走到国王和皇后的位置
> 然后再判断下有没有相同的位置

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
const int INF = 1e9 + 50;

int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};

void solve() {
    int x1, x2, y1, y2, a, b;
    std::cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    std::set<std::pair<int ,int>> s1, s2;
    for(int i = 0 ; i < 4 ; i++){
        s1.insert({x1+dx[i]*a, y1+dy[i]*b});
        s1.insert({x1+dx[i]*b, y1+dy[i]*a});
        s2.insert({x2+dx[i]*a, y2+dy[i]*b});
        s2.insert({x2+dx[i]*b, y2+dy[i]*a});
    }
    int cnt = 0;
    for(auto i : s1){
        if(s2.find (i) != s2.end())
            cnt ++;
    }
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

# B [Collecting Game](https://codeforces.com/contest/1904/problem/B)

## 题目大意

> 给一个数组`a`,对于每一个元素,我们都会有一个初始值`w = a[i]  (0 <= i < n)`只要`w`大于或等于数组中的某个元素,`w = w + a[k]`并且就会把这个数删除掉.
>
> 问: 对于每个元素,至多可以删除多少元素?

## 解题思路

> 由于需要最大化删除个数,我们可以先对数组升序排序,这样对于`i(0 <= i < n)` 就可以将`0 ~ i-1`的所有数删除掉,然后再考虑后面的.
>
> 就这样模拟下过程就完事儿了.

## 代码

(提交的一次TLE的代码)

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
typedef std::pair<int, int> pii;

void solve() {
    int n;
    std::cin >> n;
    pii a[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i].first, a[i].second = i;
    std::sort(a, a + n);
    std::vector<int> s(n, 0ll);
    for (int i = 0; i < n; i++) {
        if (i == 0)
            s[i] = a[i].first;
        else
            s[i] = s[i - 1] + a[i].first;
    }
    std::vector<int> ans(n, 0ll);
    for (int i = 0; i < n; i++) {
        int t = s[i], j = i + 1;
        while (j < n && t >= a[j].first)
            t += a[j++].first;
        ans[i] = j - 1;
    }
    for (int i = 0; i < n; i++)
        a[i].first = ans[i];
    std::sort(a, a + n, [&](pii aa, pii bb) {
        return aa.second < bb.second;
    });
    for(int i = 0 ; i < n ; i ++){
        std::cout << a[i].first << " ";
    }
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

(AC代码)

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]] const int INF = 1e9 + 50;

typedef std::pair<int, int> pii;

void solve() {
    int n;
    std::cin >> n;
    pii a[n + 1];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    std::sort(a, a + n);
    std::vector<int> b(n, 0ll), c(n, 0ll), d(n, 0ll);
    for (int i = 0; i < n; i++) {
        b[i] = a[i].first;
        if (i == 0)
            c[i] = b[i];
        else
            c[i] = c[i + 1] + b[i];
    }
    for (int i = 0; i < n; i++) {
        int t = c[i];
        int k = t;
        while (true) {
            int w = std::upper_bound(b.begin(), b.end(), t) - b.begin();
            if (w == n) {
                d[a[i].second] = n - 1;
                break;
            } else {
                if (c[w - 1] == k) {
                    d[a[i].second] = w - 1;
                    break;
                } else {
                    k = c[w - 1];
                    t = c[w - 1];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << d[i] << " ";
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

# C [Array Game](https://codeforces.com/contest/1904/problem/C)

## 题目大意

> 给一个数组`a`,有`k`次操作,每次操作选一个`(i, j) (0 <= i < j < n)` ,将`|a[j] - a[i]|`放在数组的足以后方.
>
> 问:`k`次操作后得到的数组最小的数为多少?

## 解题思路

> 首先,可以考虑到`k>=3`时,我们可以先选两次相同的`(i, j)`,然后再选新加入的这两个,这样就可以得到`0`了`
>
> 然后再是`k == 1`时, 我们想让答案最小化,我们只能先将数组排序,然后再找相邻的两个的的差值,再到最小值后,答案还不是最优值, 所以还要与原数组最小值比较.
>
> 最后, 再是 `k == 2`时, 题目中明确告诉`n^2 < 4e6`,这就是让我们暴力循环,我们可以先将`k == 1`时的最小值记录下来,然后再暴力`n^2`跑一遍数组,再与之前的比较一下,最后输出答案.

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a.push_back(x);
    }
    if (k >= 3) {
        std::cout << 0 << endl;
        return;
    }
    std::sort(a.begin(), a.end());
    auto calc = [&]() {//相当于处理了一次
        std::sort(a.begin(), a.end());
        int ans = a[0];
        for (int i = 1; i < (int) a.size(); i++) {
            ans = std::min(ans, a[i] - a[i - 1]);
        }
        return ans;
    };

    int ans = calc();
    if (k == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = a[j] - a[i];
                int p = std::lower_bound(a.begin(), a.end(), w) - a.begin();
                if (p != n - 1)
                    ans = std::min(ans, a[p] - w);
                if (p != 0)
                    ans = std::min(ans, w - a[p - 1]);
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