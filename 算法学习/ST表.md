$O(n\log_2{n})$预处理,$O(n)$询问区间最大值
对于一个数组，我们需要在$O(n\log_2{n})$时间内求出区间的最大值
ST表是基于倍增算法的
$f_{i,j}$ 表示从 $a_i$ 开始长度为$2^{j},[i,i+2^{j} - 1]$的区间的最大值
我们设$f_{i,j}$表示区间$[i,i+ 2^{j} - 1]$内的最值，显然 $f_{i,0} = max[i,i] = num_i$。
由倍增思想可得，跳 $2^i$ 步相当于先跳 $2^{i - 1}$ 步再跳 $2^{i - 1}$ 步；同理区间 $[i,i+2^{j}-1]$ 内的最值相当于是区间 $[i,i+2^{j-1}-1]$ 和 $[i+2^{j-1}, i+2^{j}-1]$ 内的最值。
所以可得式子 $f_{i,j}=max(f_{i,j-1},f_{i+2^{j-1},j-1})$ 。
则只需要枚举起点（也就是枚举 $i$ ），接着枚举区间长度（也就是枚举 $j$ ），使得整个区间被包进去，就可以构建出ST表了。
对于每次询问：
当询问区间 $[l,r]$ 内的最值时，我们当然希望直接输出 $f_{l,x},(l+2^{x}-1=r)$ 。
由上式子可以得到 $x=\log_2{r-l+1}$ 。
但问题来了，我们要求 $j$ 得是个整数，但经过对数运算后出的 $x$ 可能是个非整数，若是对其进行取整，向下取整可能使区间变小，向上取整又可能使区间变长，显然怎么都不太合适。
![[Drawing 2024-03-14 18.45.42.excalidraw.png]]
对区间 $[1,9]$ 来说，向下取整变成 $[1,7]$ ，向上取整变成 $[1,15]$

所以这里有一个办法，那就是把区间 $[l,r]$ 分为两个子区间。一部分是向下取整得到的 $[l,l+2^{\log_2{r-l+1}}-1]$ 也就是 $f_{l, \lfloor x \rfloor}$ 。
为了防止向下取整使得区间可能变小带来的影响，我们再塞一个新区间 $[r-2^{x}+1,r]$ 。
![[v2-d48868ec65e6db7ea29715d013131706_1440w.webp]]

由于是可重复贡献问题，虽然两区间有所重叠，但不会造成影响。

```c++
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define fix(n) std::fixed << std::setprecision(n)
[[maybe_unused]] const int INF = 1e17 + 50, MOD = 1e9 + 7, N = 2e5 + 50;
[[maybe_unused]] typedef std::pair<int, int> pii;

void solve() {
	int n, t, q, x, y;
	std::cin >> n >> t >> q;
	std::vector<int> Log(N, 0ll);
	std::vector<std::vector<int> > st(n + 1, std::vector<int>(50, 0ll));
	Log[1] = 0;
	for (int i = 2; i <= n; i++) Log[i] = Log[i >> 1] + 1;
	for (int i = 1; i <= n; i++) std::cin >> st[i][0];
	for (int j = 1; j <= Log[n]; j++) {
		for (int i = 1; i <= n - (1 << j) + 1; i++) {
			st[i][j] = std::max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}

	while (t--) {
		std::cin >> x >> y;
		int k = Log[y - x + 1];
		int t = std::max(st[x][k], st[y - (1 << k) + 1][k]);
		std::cout << t << ' ' << (t >= q ? "YES" : "NO") << endl;
	}
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

