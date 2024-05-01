---
tags:
  - 题解
  - atcoder
---
# A [Penalty Kick](https://atcoder.jp/contests/abc348/tasks/abc348_a)
## 题目描述
> 输出`n`个字符，每两个`o`后输出一个`x`
## 参考代码
```cpp
#include<bits/stdc++.h>

#define int long long
#define endl '\n'
#define pii std::pair<int ,int>
const int inf = 1e17 + 50;

void solve() {
    int n;
    std::cin >> n;
    for(int i = 1; i <= n ;i ++) {
        std::cout << (i % 3 ? "o" : "x");
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int TT = 1;
//    std::cin >> TT;
    while (TT--) solve();
    return 0;
}
```

# B [Farthest Point](https://atcoder.jp/contests/abc348/tasks/abc348_b)
## 题目描述
> 给定坐标系上`n`个点，依次输出每个点距离最远的点的编号，若有相同距离的，则输出编号最小的。
## 解题思路
>暴力求解
## 参考代码
```cpp
#include<bits/stdc++.h>

#define int long long
#define endl '\n'
#define pii std::pair<int ,int>
#define f(x) (x*x)
#define fix(x) std::fixed << std::setprecision(x)
const int inf = 1e17 + 50;

struct node {
    double x, y;
};

double dis(node aa, node bb) {
    int x = f((aa.x - bb.x));
    int y = f((aa.y - bb.y));
    return sqrt((double) (x + y));
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<node> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].x >> a[i].y;
    }

    for (int i = 0; i < n; i++) {
        int pos = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (dis(a[i], a[j]) > dis(a[i], a[pos])) {
                    pos = j;
                }
            }
//            std::cout << dis(a[i], a[j]) << endl;
        }
        std::cout << pos + 1 << endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int TT = 1;
//    std::cin >> TT;
    while (TT--) solve();
    return 0;
}
```

# C [Colorful Beans](https://atcoder.jp/contests/abc348/tasks/abc348_c)
## 题目描述
> 有`n`个豆子，豆子有颜色和美味值，我们可以选择一个颜色的豆子，并吃掉其中一个，通过选择，最大限度地减少所吃豆子的美味度。

## 解题思路
>首先，我们要选择一个颜色的豆子，并且使其最大值最小化，那么我们可以先预处理出每个颜色的豆子的最小值，然后再在这几个颜色的豆子中找出最大值，最大值即为答案。

## 参考代码
```cpp
#include<bits/stdc++.h>  
  
#define int long long  
#define endl '\n'  
#define pii std::pair<int ,int>  
#define f(x) (x*x)  
#define fix(x) std::fixed << std::setprecision(x)  
const int inf = 1e17 + 50;  
  
void solve() {  
    int n;  
    std::cin >> n;  
    std::map<int, int> mp;  
    for (int i = 0, x, y; i < n; i++) {  
        std::cin >> x >> y;  
        if (mp.contains(y)) {  
            mp[y] = std::min(x, mp[y]);  
        } else {  
            mp[y] = x;  
        }  
    }  
    int ma = -inf;  
    for (auto [x, y]: mp) {  
        ma = std::max(ma, y);  
    }  
  
    std::cout << ma << endl;  
}  
  
signed main() {  
    std::ios::sync_with_stdio(false);  
    std::cin.tie(nullptr), std::cout.tie(nullptr);  
    int TT = 1;  
//    std::cin >> TT;  
    while (TT--) solve();  
    return 0;  
}
```

# D [Medicines on Grid](https://atcoder.jp/contests/abc348/tasks/abc348_d)
## 题目描述
