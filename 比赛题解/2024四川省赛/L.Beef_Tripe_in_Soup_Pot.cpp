#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii std::pair<int ,int>
#define fix(x) std::fixed << std::setprecision(x)
const int inf = 1e17 + 50, MAX_N = 1e5 + 50, mod = 1e9 + 7;

void solve() {
    int n;
    std::cin >> n;
    std::vector<pii> A, B;
    for(int i = 1; i <= n ; i ++) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        if(c == d) {
            if(a < b) A.push_back({a, i});
            else B.push_back({b, i});
        }else if(c == 1) {
            A.push_back({a, i});
        }else if(d == 1) {
            B.push_back({b, i});
        }
    }

    std::sort(A.begin(), A.end(), [&] (pii aa, pii bb){
        return aa.first < bb.first;
    });

    std::sort(B.begin(), B.end(), [&] (pii aa, pii bb) {
        return aa.first < bb.first;
    });

    std::cout << A.size() << ' ';
    for(auto [x, y] : A) {
        std::cout << y << ' ';
    }
    std::cout << endl << B.size() << ' ';
    for(auto [x, y] : B) {
        std::cout << y << ' '; 
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