# [Educational Codeforces Round 159 (Rated for Div. 2)](https://codeforces.com/contest/1902)

## A [Binary Imbalance](https://codeforces.com/contest/1902/problem/A)

### 题目大意

> 给定一个长度为`n`的一个`01`字符串，我们执行以下操作：
> 当`s[i]!=s[i+1]`在中间插入`0`
> 问：是否可以实现`0`的个数大于`1`的个数

### 解题思路

> 由题意可以明显看出只要有`0`就可以实现。下面简单分析下：
>
> 1. `0`的个数大于0，`1111110`我们可以在子串`10`中间一直插入`0`
> 2. `0`的个数为`0`时， `11111111`不可能在字符串中插入`0`

### 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
const int INF = 0x3f3f3f3f;

void solve(){
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    for(auto i : s)
        if(i == '0'){
            std::cout << "YES" << endl;
            return;
        }
        std::cout << "NO" << endl;
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

---

## B [Getting Points](https://codeforces.com/contest/1902/problem/B)(贪心)

### 题目大意

> `n`天里面要获得`p`分,可以通过两个路径获取分数:
>
> 1. 每天上一堂课,可获得`i`分.
> 2. 进行一次实践,可获得`t`分,但是实践==每七天才会有一个==, ==每一天最多可以做两个实践==
>
> 其中, 一天可以选择休息或者学习, 问最多可以休息多少天.

### 解题思路

> 可以将所有任务放在最后几天

### 代码

(大佬们指点一下)

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
const int INF = 0x3f3f3f3f;

void solve(){
    int n, p, L, t;
    std::cin >> n >> p >> L >> t;
    int l = 1, r = n, ans =0 ;
    while(l <= r){
        int mid =(l + r)>>1;
        if((n - mid + 1)* L +std::min((n + 6) / 7,(n - mid + 1)* 2 ) * t>= p) ans = mid ,l = mid + 1;
        else r = mid - 1;
    }
    std::cout << ans - 1 << endl;
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

## C [Insert and Equalize](https://codeforces.com/contest/1902/problem/C)

### 题目大意

> 给你一个整数数组 `a[1],a[2],...,a[n]`所有元素都是不同的。
>
> 首先，要求你在这个数组中再插入一个整数 `a[n+1]，a[n+1]` 不应等于 a1,a2,...,an。
>
> 然后，你必须使数组中的所有元素相等。一开始，你选择一个==正整数==`x(x\>0 )`在一次操作中，你将 `x `恰好加到数组的一个元素上。
> ==注意，所有操作中 x 都是相同的==。
> 在你选择 `a[n+1]`和 `x` 之后，使所有元素相等的最小操作次数是多少？

### 解题思路

> 假设数组`a` 中有元素`x, y, z `(三者互不相等, 其中 z 最大) , 那么我们就需要找到一个数`w`,使得 `x+k1*w=z, y+k2*w=z`
> 显然就可以看出一个性质`w=gcd(abs(x-y), abs(y-z))`
> 就这样我们找到了题目中的`x`,接下来, 我们需要找插入的`a[n+1]`
> 令 `ma=max(a)`,因为元素互不相等, 我们就需要找插入比`ma`大`k*w` 和比`ma`小`k*w`的两个数,
> 分别重新找出最大值, 并计算所有元素加到`ma`的次数
> 输出两种情况下最小的次数.

### 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
const int INF = 0x3f3f3f3f;

void solve(){
    int n;
    std::cin >> n;
    std::vector<int> a, b;
    std::map<int , int> mp;
    for(int i = 0 ; i < n ; i ++){
        int x;
        std::cin >> x,a.push_back(x), b.push_back(x), mp[a[i]] = 1;
    }

    int w = unique(a.begin (), a.end()) - a.begin ();
    if(w == 1){
        std::cout << 1 << endl;
        return ;
    }
    int o = abs(a[1] - a[0]);
    for(int i = 2 ; i < n ; i ++)
        o = std::__gcd(abs(a[i] - a[i - 1]), o);
    // std::cout << o << endl;
    int cnt = 0;
    int k1 = *std::max_element (a.begin (), a.end ());
    while(true){
        cnt ++;
        if(mp[k1 - cnt * o] != 1){
            a.push_back (k1 - cnt * o);
            break;
        }
    }
    k1 = *std::max_element (a.begin (), a.end ());
    int ans1 = 0, ans2 = 0;
    for(int i = 0 ; i < (int)a.size(); i ++)
        ans1 += abs(a[i] - k1) / o;
    cnt = 0;
    int k2 = *std::max_element (b.begin (), b.end ());
    while(true){
        cnt ++;
        if(mp[k2 + cnt * o] != 1){
            b.push_back (k2 + cnt * o);
            break;
        }
    }
    k2 = *std::max_element (b.begin (), b.end ());
    for(int i = 0 ; i < (int)b.size(); i ++)
        ans2 += abs(a[i] - k2) / o;
    std::cout << std::min(ans1, ans2) << endl;

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

## D [Robot Queries](https://codeforces.com/contest/1902/problem/D)

### 题目描述

> 给一个长度为n 的字符串和q次询问, 机器人开始在`(0,0)`
> 机器人可以执行四条指令：
>
> 1. U-- 从点`(x,y)` 移动到 `(x,y+1)` ；
> 2. D-- 从点`(x,y)` 移动到 `(x,y−1)`；
> 3. L--从点 `(x,y)` 移动到 `(x−1,y)`；
> 4. R--从点 `(x,y)` 移动到 `(x+1,y)`。
>    每次询问四个数x, y, l, r ,
>    判断机器人是否访问过点(x, y),但字符串l 到 r 的字串是相反的.
>

### 代码

(TLE 13)

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
const int INF = 0x3f3f3f3f;

void solve(){
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    s = " " + s;
    while(q --){
        int x = 0, y = 0, N, M, l, r;
        std::cin >> N >> M >> l >> r;
        std::string str(s);
        bool f = false;
        reverse (str.begin() + l, str.begin () + r + 1);
        // std::cout << str << endl;
        for(int i = 1; i < (int) str.size() ;i ++){
            if(x == N && y == M){
                std::cout << "YES" << endl;
                f = true;
                break;
            }
            if(str[i] == 'U')y ++;
            else if(str[i] == 'D') y --;
            else if(str[i] == 'L') x --;
            else x ++;
            if(x == N && y == M){
                std::cout << "YES" << endl;
                f = true;
                break;
            }
            // std::cout << x << " " << y << endl;
        }
        if(!f)
            std::cout << "NO" << endl;
    }
}

signed main () {
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr), std::cout.tie (nullptr);
    int Lazy_boy_ = 1;
    // std::cin >> Lazy_boy_;
    while (Lazy_boy_--)
        solve ();
    return 0;
}
```
