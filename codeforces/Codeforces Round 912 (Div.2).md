
## A [Halloumi Boxes](https://codeforces.com/contest/1903/problem/A)

### 题目大意

> 给定一个数组A,我们可以对数组惊醒多次操作,操作如下:
> 我们可以将数组中的某一段倒置,但是长度不能超过K,例如:反转子数组意味着选择两个索引i和j(其中 1 <= i <= j <= n )
> 并将数组
>
 $$
 a_1,a_2,…,a_n
 $$
>
> 改为
>
$$
 a_1,a_2,…,a_{i−1},a_{j},a_{j−1},…,a_{i},a_{j+1},…,a_{n-1},a_n
 $$
>
> `(j − i + 1 <= k )` 。

### 分析

> 由于可以操作多次,那么我们可以判断下k是否为1:
>
> 1. 若k = 1时, 我们只能反转一个元素,显然是无效的, 我们就只需要判断数组是否为有序
> 2. 若k > 1时,显然是可行的

### 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

void solve () {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n, 0), b(n, 0);
    for(int i = 0 ; i < n ; i ++) 
        std::cin >> a[i], b[i] = a[i];

    std::sort(b.begin (), b.end ());
    bool f = true;
    for(int i = 0 ; i < n ; i ++){
        if(a[i] != b[i]){
            f = false;
            break;
        }
    }
    if(f) 
        std::cout << "YES" << endl;
    else {
        if(k > 1)
            std::cout << "YES" << endl;
        else 
            std::cout << "NO" << endl;
    }
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

## B [StORage room](https://codeforces.com/contest/1903/problem/B)

### 题目大意

> 给定一个数`n`,和一个`n*n`的数组`M`,数组
>
> $$
 M_{i,j}
 $$
>
> 表示为:
>
> $$
 M_{i,j} = \begin{cases} a_i|a_j,(i \not= j)\\\\ 0, (i == j)\end{cases}(M_{i,j} < 2 ^{30})
 $$
>
> 让我们判断是否存在这样的一个数组a满足上式,若存在输出YES和数组a
> 否则输出NO

### 分析

> 现在我有两个数`x, y`,如果我将这两个数进行或运算后`(w = x | y)`, 在二进制状态下`x`和`y`在某一位上有一个为`1`,则该位为`1`
> 通过这个我们可以发现在
>
> $$
M_i
 $$
>
> 中,
>
> $$
M_{i,0} = a_i | a_0, M_{i,1} = a_i | a_1, ........, M_{i,n - 1} = a_i | a_{n - 1}
 $$
>
> , 我们可以通过与运算将
>
> $$
 a_i
 $$
>
> 计算出来, 但是在运算时我们需要排除
>
> $$
M_{i,j}(i==j)
 $$
>
> ;
> 在计算完后我们可以遍历一次M数组,判断
>
> $$
 M_{i,j}=a_i|a_j(i \not= j)
$$
>

### 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

void solve () {
    int n;
    std::cin >> n;
    std::vector<int> a(n, 0);
    std::vector<std::vector<int> > m(n, std::vector<int> (n, 0));
    for(int i = 0 ; i < n ; i ++){
        int x = -1;
        for(int j = 0;j < n;j ++){
            std::cin >> m[i][j];
            if(i != j){
                if(x == -1)
                    x = m[i][j];
                x &= m[i][j];
            }
        }
        a[i] = x;
    }
    if(n == 1){//特殊情况,可任意输出一个数
        std::cout << "YES" << endl << 1 << endl;
        return ;
    }
    auto check = [&] (){
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j ++){
                int x = a[i] | a[j];
                if(m[i][j] != x && i != j){
                    return false;
                }
            }
        }
        return true;
    };
    if(check()){
        std::cout << "YES" << endl;
        for(int i = 0 ; i < n ; i ++)
            std::cout << a[i] << " ";
        std::cout << endl;
    }
    else 
        std::cout << "NO" <<endl;
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

## C [Theofanis' Nightmare](https://codeforces.com/contest/1903/problem/C)(贪心)

### 题目大意

> 给定一个数组`a`,大小为`n`,现在将数组`a`分割成几个非空子数组,并且保证每个元素只在一个一个子数组中,例如，数组 `[1,−3,7,−6,2,5]`可以划分为 `[1][−3,7][−6,2][5]`。
> 这种分割的值等于
>
> $$
 \sum_{i=1}^k i*sum_i
 $$
>
> ，其中`k`是我们将数组分割成的子数组的个数，
>
> $$
 sum_i
 $$
>
> 是第`i`个子数组的和。
> 这个数组的值为
>
> $$
 [1][−3,7][−6,2][5]=1\times 1+2\times (−3+7)+3\times (−6+2)+4\times5=17
 $$
>
> 现在让我们求分割的最大值为多少?

### 分析

> 先考虑每个子段的数字贡献，i* sum_i也可以转化为该子段中每个数字被加上了i次。那么就可以把乘法转化为加法。
> 然后考虑怎么划分子段最优，如果从前往后考虑，很难判断是否该将当前数字划分为一个新子段的起点。
> 因此，需要从后往前遍历，统计i∼n之间的数字总和，为了使答案尽可能大，那么只要当前数字总和大于等于0，就可以将当前位置划分给一个新的子段起点。
> 此时，划分出一个新的起点后，那么后面所有的数字均需要再被加上一次，不难发现，此时要加上的就是维护的数字总和。
> 由于第一个元素也可能被划分到一个新的子段中，为了避免重复计算，当遍历到第一个元素时，必须将当前元素视为子段起点，加上维护的数字总和。

### 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

void solve () {
    int n;
    std::cin >> n;
    std::vector<int> a(n, 0);
    for(int i = 0 ; i < n ; i ++)
        std::cin >> a[i];
    int ans = 0, w = 0;
    for(int i = n - 1; i >= 0 ; i --){
        w += a[i];
        if(i == 0 || w > 0)
            ans += w; 
    }
    std::cout << ans << endl;
}


signed main () {
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr), std::cout.tie (nullptr);
    int Lazy_boy = 1;
    std::cin >> Lazy_boy;
    while (Lazy_boy--)
        solve ();
    return 0;
}
```

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

void solve () {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1, 0ll), s(n + 1, 0ll);
    for(int i = 1 ; i <= n ; i ++)
        std::cin >> a[i], s[i] = s[i - 1] + a[i];
    int ans = 0, w = 0;
    for(int i = 1; i <= n ; i ++){
        if(i == 1 || s[n] - s[i - 1] >= 0) 
            w ++;
        ans += w * a[i];
    }
    std::cout << ans << endl;
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

## D1 [Maximum And Queries (easy version)](https://codeforces.com/contest/1903/problem/D1)

### 题目大意

> 给出一个长度为n的数组a，并进行q次询问，每次询问为：
> 你可以进行`k`次操作，每次从数组a中选择一个元素，让这个元素 `+ 1`。
>  问：经过`q`次操作后,
>
> $$
 a_1,a_2,.....,a_n
 $$
>
> 的与的最大值是多少
> 注：每次询问都是独立的，不会保留前面询问的操作结果。

### 分析

> 由于每次询问都是独立的，那么修改不能在原数组上进行，需要将原数组元素复制到其他数组中再进行操作。
> 题目数据规定了
>
> $$
 n\times q≤10^5
 $$
>
> ，那么可以认为最大的数据就是对长度为
>
> $$
 10^5
 $$
>
> 的数组进行一次询问。
> 由于给出的
>
> $$
 k≤10^{18}
 $$
>
> ，那么当数组中只有一个元素时，最大可能的结果为
>
> $$
 10^{18}+10^6≈2^{60}
 $$
>
> ，因此需要一个大于`60`的数组记录与运算后的结果每位二进制数是多少。
> 对于每次询问，从二进制高位开始往低位进行遍历，每次检查当前剩余的k是否还能将数组中所有数的当前二进制位修改为1
> 如果可以，进行修改，并记录在答案数组中，如果不行，继续遍历更低的二进制位。
> 结束修改后，将数组中记录的信息转化为十进制数即可。
>
> **本题数据较大，需要注意使用左移运算需要使用1ll将1转化为long long类型再进行运算，计算花费时也要考虑如果超过操作次数就该退出检查，避免数据溢出。**

### 代码

```cpp
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
const int N = 1e5 + 5;

int a[N], b[N], ans[105];
int n, q;

int getCost(int x, int k) {
    int cost = 0;
    for (int j = 1; j <= n; j++) {
        if ((b[j] & (1ll << x)) == 0) {
            //使用位运算计算将b[j]的第x位二进制修改为1需要加上多少
            cost += (1ll << x) - ((1ll << (x + 1)) - 1ll & b[j]);
        }
        if (cost > k) return cost; //超过k就返回，避免数据溢出
    }
    return cost;
}

void solve() {
    std::cin >> n >> q;
    for(int i = 1; i <= n ; i ++)
        std::cin >> a[i];
    while(q --){
        int k;
        std::cin >> k;
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; i++) 
            b[i] = a[i];
        for (int i = 60; i >= 0; i--) {//检查第i位结果与运算的结果是否可能为1
            int cost = getCost(i, k);
            if (cost <= k) {//花费在操作次数范围内
                ans[i] = 1;//与运算结果可以为1
                k -= cost;
                for (int j = 1; j <= n; j++) {
                    if ((b[j] & (1ll << i)) == 0) {
                        //通过或运算将2^i位修改为1，再通过与运算将后面数字清0
                        b[j] = ((b[j] | (1ll << i)) & (1ll << i));
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= 60; i++)
            res |= (ans[i] << i);//这里ans[i]如果不是long long类型也会发生溢出
        std::cout << res << endl;
    }
}


signed main () {
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr), std::cout.tie (nullptr);
    int Lazy_boy = 1;
    // std::cin >> Lazy_boy;
    while (Lazy_boy--)
        solve ();
    return 0;
}
```
