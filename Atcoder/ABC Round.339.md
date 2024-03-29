# A  [TLD](https://atcoder.jp/contests/abc339/tasks/abc339_a)

## 题目描述
>给定字符串`s`,输出字符串中`.`(点)后面的字符,若有多个`.`输出最后一个`.`的信息.
## 解题思路
>有多种解法,可以暴力循环一次,或者用`find()`函数查找

## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 1e9 + 1;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    std::string s;
    std::cin >> s;
    int pos = 0, t = -1;
    while ((pos = s.find('.', pos)) != -1)
        t = pos, pos++;
    std::cout << s.substr(t + 1) << endl;
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

# B [Langton's Takahashi ](https://atcoder.jp/contests/abc339/tasks/abc339_b)

## 题目描述
> 给三个数`n`,`m`和`k`,其中`n` `m`代表`n * m`的矩阵,`k`代表操作数
> 起始点在矩阵的`(1,1)`,朝向为正上方
> 对于每次操作:
> 1. 当前位置为`.` 则将当前位置改为`#` 并且向右转,向前走一步.
> 2. 当前位置为`#` 则将当前位置改为`.` 并且向左转,向前走一步.
> 打印出矩阵作为结果
## 解题思路
>使用矩阵模拟下过程即可
>对于样例`3  4  5`模拟下
>初始状态`x = 1, y = 1`朝向正上方
$$\begin{matrix}
.&.&.\\
.&.&.\\
.&.&.\\
.&.&.\\
\end{matrix}
$$
第一步,由于当前位置`(1,1)`为`.`那么就需要将当前位置变为`#`,并向右转,走一步到`(1,2)`,朝向右
$$\begin{matrix}
\#&.&.\\
.&.&.\\
.&.&.\\
.&.&.\\
\end{matrix}
$$
第二步,由于当前位置`(1,2)`为`.`那么就需要将当前位置变为`#`,并向右转,走一步到`(2,2)`,朝向下
$$\begin{matrix}
\#&\#&.\\
.&.&.\\
.&.&.\\
.&.&.\\
\end{matrix}
$$
第三步,由于当前位置`(2,2)`为`.`那么就需要将当前位置变为`#`,并向右转,走一步到`(2,2)`,朝向左
$$\begin{matrix}
\#&\#&.\\
.&\#&.\\
.&.&.\\
.&.&.\\
\end{matrix}
$$
第四步,由于当前位置`(2,1)`为`.`那么就需要将当前位置变为`#`,并向右转,走一步到`(1,1)`,朝向上
$$\begin{matrix}
\#&\#&.\\
\#&\#&.\\
.&.&.\\
.&.&.\\
\end{matrix}
$$
第五步,由于当前位置`(1,1)`为`#`那么就需要将当前位置变为`.`,并向左转,走一步到`(1,3)`,朝向左
,此处能到`(1,3)`是因为矩阵相当于上下,左右连通的.
$$\begin{matrix}
.&\#&.\\
\#&\#&.\\
.&.&.\\
.&.&.\\
\end{matrix}
$$
最后就得到了这样的矩阵.对于朝向的转换就需要一定的技巧,合理运用模`(mod)`的运算.
## 参考代码
```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
[[maybe_unused]]const int INF = 1e9 + 1;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> s(n, std::string(m, '.'));
    int x = 0, y = 0;
    int dx[] = {0, 1, 0, -1},
            dy[] = {1, 0, -1, 0};
    int t = 3;
    while (k--) {
        if (s[x][y] == '.')
            s[x][y] = '#', t = (t + 1) % 4;
        else
            s[x][y] = '.', t = (t + 3) % 4;
        x = (x + n + dx[t]) % n;
        y = (y + m + dy[t]) % m;
    }
    for (int i = 0; i < n; i++)
        std::cout << s[i] << endl;
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
# C [](https://atcoder.jp/contests/abc339/tasks/abc339_c)

## 题目描述
>
## 解题思路
>

## 参考代码
```cpp

```

# D [](https://atcoder.jp/contests/abc339/tasks/abc339_d)

## 题目描述
>
## 解题思路
>
