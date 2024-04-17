[传送门](https://ac.nowcoder.com/acm/contest/80259)
# A [小红进地下城](https://ac.nowcoder.com/acm/contest/80259/A)

## 题目描述
> 判断输入的两个字符串是否相等

## 参考代码
```cpp
#include<bits/stdc++.h>

#define int long long
#define endl '\n'
#define pii std::pair<int ,int>
#define fix(x) std::fixed << std::setprecision(x)
const int inf = 1e17 + 50, MAX_N = 3e6 + 50;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    std::cout << (s == t ? "Yes" : "No") << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int TT = 1;
//     std::cin >> TT;
    while (TT--) solve();
    return 0;
}
```

# B [小红打怪](https://ac.nowcoder.com/acm/contest/80259/B)

## 题目描述
>给定`n` `m`,一个方向`t`，和一个`n*m`的一个字符矩阵，其中字符矩阵的字符`A`表示当前位置，问在当前位置朝方向`t`可以打多少怪。
>`*`表示怪，`.`表示空格。
## 解题思路
>简单模拟下过程就行了。
>先找到当前位置，根据给的方向判断有多少个`*`。

## 参考代码
```cpp
#include<bits/stdc++.h>

#define int long long
#define endl '\n'
#define pii std::pair<int ,int>
#define fix(x) std::fixed << std::setprecision(x)
const int inf = 1e17 + 50, MAX_N = 3e6 + 50;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int x = 0, y = 0;
    std::string s[n];
    for(int i = 0 ; i < n ; i ++ ) {
        std::cin >> s[i];
        for(int j = 0 ;j < m ; j ++) {
            if(s[i][j] != '.' && s[i][j] != '*') {
                x = i;
                y = j;
            }
        }
    }

    int ans = 0;
    if(s[x][y] == 'A') {
        for(int i = 0 ; i < y ; i ++) {
            ans += s[x][i] == '*';
        }
    }

    else if(s[x][y] == 'D') {
        for(int i = m - 1 ; i > y ; i --) {
            ans += s[x][i] == '*';
        }
    }

    else if(s[x][y] == 'W') {
        for(int i = 0 ; i < x ; i ++) {
            ans += s[i][y] == '*';
        }
    }

    else {
        for(int i = n - 1 ; i >= x; i --) {
            ans += s[i][y] == '*';
        }
    }

    std::cout << ans << endl;
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
# C [小红的排列构造](https://ac.nowcoder.com/acm/contest/80259/C)

## 题目描述
  
>小红拿到了一个长度为`n`的数组`a`，她希望你构造两个排列`p`和`q`， 满足对于$1 \le i \le n$,  $a_i$ 为$p_i$ 或$q_i$ ,若存在这两个序列,则输出这两个序列,否则输出`-1`.
## 解题思路
>首先对于两个排列,若组合后,不会出现一个数字出现三次,我们就只需要判断下,一个数出现的次数是否满足$mp_{i} \le 2$.
>若存在这样的两个序列,我们就需要对每个数出现的位置进行处理,并分别标记这个序列中出现过哪些数字.
>我们优先满足 $p$ 序列含有该数字, 并分别标记两个序列出现的数字
>若数字 $x$ 出现了两次 $pos_{1}, pos_{2}$ , 我们可以将$p_{pos_{1}} = x, q_{pos_{2}} = x$.
>同理,数字 $x$ 出现一次$pos_{1}$,将$p_{pos_{1}}= x$ 
>最后再将没出现过的数字依次填入两个序列.

## 参考代码
```cpp
#include<bits/stdc++.h>

#define int long long
#define endl '\n'
#define pii std::pair<int ,int>
#define fix(x) std::fixed << std::setprecision(x)
const int inf = 1e17 + 50, MAX_N = 3e6 + 50;

void solve() {
    int n, flag = 1;
    std::cin >> n;
    std::map<int ,int> mp;
    std::vector<int> a(n, 0);
    std::vector<std::vector<int> > pos(n + 1);
    auto p = a, q = a;
    for(int i = 0 ; i < n ; i ++) {
        std::cin >> a[i];
        mp[a[i]] ++;
        if(mp[a[i]] > 2) {
            flag = 0;
        }
        pos[a[i]].push_back(i);
    }

    if(!flag) {
        std::cout << -1 << endl;
        return ;
    }

    std::vector<bool> sta(n + 1, false), stb(n + 1, false);
    for(int i = 1; i <= n; i ++) {
        if(pos[i].size() == 1) {
            p[pos[i][0]] = i;
            sta[i] = true;
        }else if(pos[i].size() == 2) {
            p[pos[i][0]] = i;
            q[pos[i][1]] = i;
            sta[i] = true;
            stb[i] = true;
        }
    }

    int cnt1 = 1, cnt2 = 1;
    for(int i = 0 ; i < n ; i ++) {
        while(sta[cnt1]) cnt1 ++;
        while(stb[cnt2]) cnt2 ++;
        // std::cout << i << ' ' << cnt1 << ' ' << cnt2 << endl;
        if(p[i] == 0) {
            p[i] = cnt1;
            sta[cnt1] = true;
        }
        if(q[i] == 0) {
            q[i] = cnt2;
            stb[cnt2] = true;
        }
    }

    for(int i = 0 ; i < n ;i ++ ) {
        std::cout << p[i] << " \n"[i == n - 1];
    }

    for(int i = 0 ; i < n ;i ++ ) {
        std::cout << q[i] << " \n"[i == n - 1];
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

# D [小红升装备](https://ac.nowcoder.com/acm/contest/80259/D)

## 题目描述
> ![](http://tuchuang.lazy-boy-acmer.cn/images/202404172136860.png)
## 解题思路
> 就是一个典型的 $dp$ 题. 定义 $dp_{i,j}$ 表示前 $i$ 件装备,花费 $j$ 的金币可以获得的最大战力.
> 首先,当我们不买第 $i$ 件装备,那么 $dp_{i,j}=dp_{i-1, j}$ 
> 其次,我们买第 $i$ 件装备,那么就需要考虑给这件装备升 $k$ 级, 那么就需要考虑 $price_{i} + k * cost_{i}$ 与 $j$ 的大小.若 $price_{i} + k * cost_{i}<j$, $dp_{i,j}= \max({dp_{i,j},dp_{i-1,j-price_{i}-k*cost_{i}}+att_{i}+k*upgrade_{i}})$

## 参考代码
```cpp
#include<bits/stdc++.h>

#define int long long
#define endl '\n'
#define pii std::pair<int ,int>
#define fix(x) std::fixed << std::setprecision(x)
const int inf = 1e17 + 50, MAX_N = 3e6 + 50;

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> att(n + 1);
    auto pr = att, up = att, co = att, lv = att;

    for(int i = 1; i <= n ; i ++) {
        std::cin >> att[i] >> pr[i] >> co[i] >> up[i] >> lv[i];
    }

    std::vector<std::vector<int> > dp (n + 50, std::vector<int> (x + 50, 0ll));

    int ans = 0;
    //dp[i][j]前i件装备花费j个金币的最大战力
    //dp[i][j] = dp[i - 1][j] || std::max(dp[i][j], dp[i - 1][j - cost] + add);
    for(int i = 1; i <= n ; i ++) {
        for(int j = 0 ; j < x ; j ++ ) dp[i][j] = dp[i - 1][j];//不买该装备

        for(int j = 0; j <= x ; j ++) {//买该装备
            
            for(int k = 0 ; k <= lv[i] ; k ++) {//装备升k级
                if(pr[i] + k * co[i] > j) break;

                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - (pr[i] + k * co[i])] + att[i] + k * up[i]);
                ans = std::max(dp[i][j], ans);
            }
        }
    }
    std::cout << ans << endl;
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