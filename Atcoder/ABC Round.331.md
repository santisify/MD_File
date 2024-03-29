# A [Tomorrow](https://atcoder.jp/contests/abc331/tasks/abc331_a)

## 题目大意

> 一年由 `M`个月组成,从 `1`月到 `M`月，每个月由 `D`天组成，从 `1`天到 `D`天。
>
> 问:在该日历中，年 `y`、月 `m`、日 `d`的下一天的日期？

## 参考代码

```C++
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

void solve(){
    int M, D;
    std::cin >> M >> D;
    int y, m, d;
    std::cin >> y >> m >> d;
    d ++;
    if(d > D){
        d -= D;
        m ++;
        if(m > M){
            m -= M;
            y ++;
        }
    }
    std::cout << y << " " << m << " " << d << endl;;
}

signed main () {
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr), std::cout.tie (nullptr);
    int Lazy_boy_ = 1;
//    std::cin >> Lazy_boy_;
    while (Lazy_boy_--)
        solve ();
    return 0;
}
```

# B [Buy One Carton of Milk](https://atcoder.jp/contests/abc331/tasks/abc331_b)

## 题目大意

> 一包 `6`个蛋 `S`元, 一包 `8`个蛋 `M`元,一包 `12`个蛋 `L`元
>
> 问:购买任意数量的每包鸡蛋时, 求至少购买 `N`个鸡蛋所需的最小价格?

## 解题思路

> 由于数据量比较小,我们可以直接三重循环暴力跑一遍.

## 参考代码

```C++
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
const int INF = 0x3f3f3f3f;

void solve(){
    int n, s, m, l;
    std::cin >> n >> s >> m >> l;
    int ans = INF;
    for(int i = 0 ; i <=100 ; i ++){
        for(int j = 0; j <= 100; j ++){
            for(int k = 0 ; k <= 100; k ++){
                int w = i * s + j * m + l * k;
                if(i * 6 + 8 * j + 12 * k >= n)
                    ans = std::min (ans, w);
            }
        }
    }
    std::cout << ans << endl;
}

signed main () {
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr), std::cout.tie (nullptr);
    int Lazy_boy_ = 1;
//    std::cin >> Lazy_boy_;
    while (Lazy_boy_--)
        solve ();
    return 0;
}
```

## C [Sum of Numbers Greater Than Me](https://atcoder.jp/contests/abc331/tasks/abc331_c)

## 题目大意

> 给一个大小为 `N`的数组 `A`,
> 问: 数组 `A`中所有大于 `A[i]`的元素之和.

## 解题思路

> `B`数组为输入的数组, 现有 `s`记录数组元素的总和,数组 `A`记录 `B`数组中大小为 `i`的
>
> 元素个数为 `A[i]`个,我们在遍历一次 `A`数组,只要 `A[i] > 0`就可以将 `A[i]`赋值为 `s - A[i] * i`
>
> 当然,同时 `s -= i * A[i]`
>
> 最后,再遍历一次数组 `B`,输出 `A[B[i]]`.

## 参考代码

```C++
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
const int INF = 0x3f3f3f3f;

void solve(){
    int n, s = 0, ans = 0,x;
    std::cin >> n;
    std::vector<int> a(1e6 + 50, 0ll), b(n, 0ll);
    for(int i = 0 ; i < n ; i ++)
        std::cin >> b[i], a[b[i]] ++, s += b[i];

    for(int i = 1 ; i <= 1000000 ;i ++){
        if(a[i]){
            s -= a[i] * i;
            a[i] = s;
        }
    }
    for(int i = 0 ; i < n ; i ++)
        std::cout << a[b[i]] << " ";
  
}

signed main () {
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr), std::cout.tie (nullptr);
    int Lazy_boy_ = 1;
//    std::cin >> Lazy_boy_;
    while (Lazy_boy_--)
        solve ();
    return 0;
}
```

# D [Tile Pattern](https://atcoder.jp/contests/abc331/tasks/abc331_d)


## 题目大意

> 有一个网格，网格中有``乘 `10^10`个方格。让(, 表示从上往下第(+1)行，从左往上第(j +) 列的方格0 ,< 10。(注意这个不寻常的索
> 分配)。每个方格都是黑色或白色。方格 (i,j) 的颜色由字符 PTi mod N]j mod ] 表示，其中 表示黑色， 表示白色。这里， mod h表示a除以的
> 余数。
> 回答Q个问题。
> 每个查询给出四个整数A,B,C,D，要求你找出以(A,B)为左上角，(C,D)为右下角的矩形区域中包含的黑色方格的个数。
