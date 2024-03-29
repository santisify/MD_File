# A [Rook](https://codeforces.com/contest/1907/problem/A)

## 题目大意

> 给一个国际象棋棋盘,有`t`次询问,每次询问给定一个棋子坐标`s` 例如 `d4`.
>
> 问: 输出这个棋子上下左右四个方向的坐标

## 解题思路

> 两个`for`循环暴力求解

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
const int INF = 0x3f3f3f3f;

void solve(){
    std::string s;
    std::cin >> s;
    for(int i = 1; i <= 8 ; i ++)//枚举当前列
        if(i != s[1] - '0')
            std::cout << s[0] << i << endl;
  
    for(int i = 0; i < 8 ; i ++)//枚举当前行
        if(i + 'a' != s[0])
            std::cout << (char)(i + 'a') << s[1] << endl;
}

signed main () {
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr), std::cout.tie (nullptr);
    int Lazy_boy_ = 1;
    std::cin >> Lazy_boy_;
    while (Lazy_boy_--)
        solve ();
    return 0;
}
```

# B [YetnotherrokenKeoard](https://codeforces.com/contest/1907/problem/B)

## 题目大意

> 有`t`次询问,每次询问会给定一个字符串`s`,
> 我们要敲击键盘拼接出这个字符串,但是存在一些规则:
>
> 1. 每次敲击`b`就会将位于这个`b`左边存在小写字母,那么就将距离`b`最近的一个删除,
> 2. 同理,当敲击大写字母时,就会删除这个`B`左边最近的一个大写字母.
>
> 问: 最后会组成一个怎样的字符串.

## 解题思路

> 这个题由于数据量比较大,就不要尝试双重循环去删除字符了
>
> 我们可以发现一个规律,我们只删除当前字符前大小写形式相同的字符,并且只能删除一次,而且是删除距离最近的,
>
> 这就有点像堆栈(后进先出),那我们就可以用栈来模拟这个过程
>
> 我们可以给每个字符做个标记,即创建一个和字符串大小相同的bool数组
>
> 若为`b`或`B`或被删除的字符标记为`false`,否则为true

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
const int INF = 0x3f3f3f3f;

void solve() {
    std::string s;
    std::cin >> s;
    std::vector<bool> f((int) s.size(), true);
    std::stack<int> a, b;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == 'b' || s[i] == 'B') {
            f[i] = false;
            if (isupper(s[i]) && !b.empty()){
                f[b.top()] = false;
                b.pop();
            }
            else if(islower(s[i]) && !a.empty()){
                f[a.top()] = false;
                a.pop();
            }
        } else {
            if(islower(s[i]))
                a.push(i);
            else
                b.push(i);
        }
    }
    while (!a.empty())
        a.pop();
    while (!b.empty())
        b.pop();
    for (int i = 0; i < (int) s.size(); i++)
        if (f[i])
            std::cout << s[i];
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

# C [Removal of Unattractive Pairs](https://codeforces.com/contest/1907/problem/C)

## 题目描述

> 有`t`次询问,每次询问给出一个长度为`n`的字符串,字符串两个字符不同则可以删除这两个字符
>
> 问: 字符串最短有多长.

## 解题思路

> 用手玩玩就`ok`

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> a(26, 0ll);
    for(auto i : s)
        a[i - 'a'] ++;
    int ma = *std::max_element(a.begin (), a.end());
    if(ma * 2 <= n)
        std::cout << n % 2 << endl;
    else 
        std::cout << n - 2 * (n - ma) << endl;
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

# D [Jumping Through Segments](https://codeforces.com/contest/1907/problem/C)

## 题目描述

> 有`t`次询问,每次询问会给`n`个`L, R`,其中第 `i` 段从坐标为`L[i]`的点开始,到坐标为`R[i]`的点结束。
> 玩家从坐标为 0 的点开始通关。在一次移动中，他们可以移动到距离不超过 k 的任意一点。
> 在第`i`次移动后，玩家必须落在第`i`段之内，即在坐标`x`处，使得 `L[i]≤x≤R[i]`。
> 这意味着,每次移动都必须在`L[i] ~ R[i]`
>
> 如果玩家按照上述规则到达了第 `n`个段落，那么这一关就算完成了。
>
> 为了不希望这个关卡太简单，所以要求确定可以完成这个关卡的最小整数`k`。
>

## 解题思路

> 核心思想就是**二分答案**.

## 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> L(n, 0ll), R(n, 0ll);
    for(int i = 0 ; i < n ; i ++)
        std::cin >> L[i] >> R[i];
    int l = 0, r = 1e16 + 50;
    auto check = [&] (int x){
        int ma = 0, mi = 0;
        for(int i = 0 ; i < n ; i ++){
            ma = std::min (ma + x, INF);
            mi = std::max (mi - x, 0ll);
            mi = std::max(mi, L[i]);
            ma = std::min(ma, R[i]);
            if(mi > ma)
                return false;
        }
        return true;
    };
    while(l < r){
        int mid = (l + r) >> 1;
        if(check (mid)) r = mid;
        else l = mid + 1;
    }
    std::cout << r << endl;
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
