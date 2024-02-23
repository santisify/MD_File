---

---
---
### A. Deadline

link:https://codeforces.com/group/ET2DSSkDXM/contest/487050/problem/A

题意 ：给定一个n和d，判断是否存在一个x使得$\lceil$ d/(x+1) $\rceil$+x<=n

思路：$\lceil$ d/(x+1) $\rceil$+x=$\lceil$ d/(x+1) $\rceil$+x+1-1=$\lceil$ d/(x+1)+(x+1) $\rceil$-1
显然当x+1等于sqrt(d)时值最小，所以只需要枚举sqrt(d),sqrt(d)+1就行了

代码 ：
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,P=131,M=30,mod=998244353,INF=2e18;
#define endl '\n'
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef long long ll;
void solve() {
    int n,d;
    cin>>n>>d;
    int p=sqrt(d);
    if(p+(d-1)/p>n&&p+1+(d-1)/(p+1)>n)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
void fast(){
    ios::sync_with_stdio( false);
    cin.tie(0),cout.tie(0);
}
signed main() {
    fast();
    int t = 1;
    cin>>t;
    while(t--)solve();
}
```

---
### B. Yet Another Meme Problem

link:https://codeforces.com/group/ET2DSSkDXM/contest/487050/problem/B

题意：给定A和B，求有多少对a，b满足a·b+a+b=conc(a,b),其中1<=a<=A,1<=b<=B，conc(a,b) 是a，b的字符串拼接，比如conc(22,10)=2210

思路 ：设f(x)，表示x有f(x)位。a·b+a+b=f(b)·a+b，即b=f(b)-1,所以显然b=99...9
所以对于每个b，任意a都是成立的，所以直接枚举b就行了

代码：
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,P=131,M=30,mod=998244353,INF=2e18;
#define endl '\n'
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef long long ll;
void solve() {
    int a,b,res=0;
    cin>>a>>b;
    int t=9;
    for(;t<=b;t=t*10+9)res+=a;
    cout<<res<<endl;
}
void fast(){
    ios::sync_with_stdio( false);
    cin.tie(0),cout.tie(0);
}
signed main() {
    fast();
    int t = 1;
    cin>>t;
    while(t--)solve();
}
```

---

### C. Two Arrays

link:https://codeforces.com/group/ET2DSSkDXM/contest/487050/problem/C

题意：给定两个整数 n 和 m 。计算数组 (a,b)对的数量，使得：

- 两个数组的长度都等于 m；
- 每个数组的每个元素都是介于 1 和 n (包括)之间的整数；
- 表示从 1 到 m 的任何索引 i都满足ai<=bi ；
- 数组 a 按非降序排序；
- 数组 b 按非升序排序。
由于结果可能非常大，因此答案要对1e9+7 取模。

思路：a是升序的，b是降序的，所有ai<=bi，由此可以知道，只要an<=bn，那么a，b数组一定是合法的。所以只需要找以每个数结尾的合法序列有多少个就行了，可以用dp,然后枚举an与bn就行了.
状态定义：`dp[i][j]`表示前i个数中以j结尾的非降序序列的个数
状态转移：`dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j-2]+... +dp[i-1][1]`

代码：
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,P=131,M=30,mod=1e9+7,INF=2e18;
#define endl '\n'
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef long long ll;
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)dp[1][i]=1;
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=j;k++){
                dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<=j)res=(res+dp[m][i]*dp[m][n-j+1])%mod;
        }
    }
    cout<<res<<endl;
}
void fast(){
    ios::sync_with_stdio( false);
    cin.tie(0),cout.tie(0);
}
signed main() {
    fast();
    int t = 1;
//    cin>>t;
    while(t--)solve();
}
```

---

### D. Minimax Problem

link:https://codeforces.com/group/ET2DSSkDXM/contest/487050/problem/D

题意：给定 n个数组 a1,a2 ,...,an。每个数组恰好由 m个整数组成。我们将第 x个数组的第 y个元素表示为 ax,y 。我们可以选择两个数组 ai 和 aj,新数组 bk=max(ai,k , aj,k)。目标是选择 i 和 j ，使数组b的最小值尽可能大。

思路：二分答案，对于每个ai,j>=x则为1，反之则为0。然后将每个a数组转换成二进制数，存在`ai|aj=(1<<m)-1`,则此答案有解，反之则无解

代码：
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,P=131,M=30,mod=1e9+7,INF=2e18;
#define endl '\n'
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef long long ll;
bool check(vector<vector<int>> &a,int n,int m,int x,int &res1,int &res2){
    vector<int> s(1<<m),p(1<<m);
    for(int i=1;i<=n;i++){
        int t=0;
        for(int j=1;j<=m;j++){
            if(a[i][j]>=x)t=t<<1|1;
            else t=t<<1;
        }
        s[t]++;
        p[t]=i;
    }
    for(int i=0;i<1<<m;i++){
        for (int j=0;j<1<<m;j++){
            if(s[i]&&s[j]&&((i|j)==(1<<m)-1)){
                res1=p[i],res2=p[j];
                return true;
            }
        }
    }
    return false;
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    int l=0,r=1e9,x,y;
    while(l<r){
        int mid=l+r+1>>1;
        if(check(a,n,m,mid,x,y))l=mid;
        else r=mid-1;
    }
    check(a,n,m,l,x,y);
    cout<<x<<" "<<y<<endl;
}
void fast(){
    ios::sync_with_stdio( false);
    cin.tie(0),cout.tie(0);
}
signed main() {
    fast();
    int t = 1;
//    cin>>t;
    while(t--)solve();
}
```

---

### E. Messenger Simulator

link:https://codeforces.com/group/ET2DSSkDXM/contest/487050/problem/E

题意：给一个排列p(初始为1,2,3,4...n),然后接收m个数字，收到x就把p中x放到第一个，x之前的数字往后移一位，求接收了所有数字的过程中，排列中每个数字最靠前以及最靠后的位置。

思路:
先看最靠前的位置:
- 如果m个数字中出现了x，那么最靠前的位置一定是1
- 如果m个数字中没有出现x，那么最靠前的位置一定是x
然后是最靠后的位置，x最靠后的位置一定在x最后的位置或者移到第1位之前最后的位置，在x第1次移到第1位之前，大于x的数第1次往第1位移动都会使得x往后移。
在x每次移到第1位之后，任何数第1次往第1位移动都会使得x往后移一位。
只需要在枚举过程中用树状数组维护这两个值就行了。

代码：
```
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,P=131,M=30,mod=1e9+7,INF=2e18;
#define endl '\n'
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef long long ll;
class TR1{
public:
    vector<int> tr;
    TR1(int k){
        tr=vector<int>(k+1);
    }
    int lowbit(int x){
        return x&-x;
    }
    void add(int x,int p){
        if(x==0)return;
        for(int i=x;i<tr.size();i+=lowbit(i))tr[i]+=p;
    }
    int sum(int x){
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))res+=tr[i];
        return res;
    }
    int query(int l,int r){
        if(l>r)return 0;
        return sum(r)-sum(l-1);
    }
};
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(m+1);
    vector<int> ans1(n+1),ans2(n+1);
    vector<int> last(n+1),st(n+1);
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++)ans1[i]=ans2[i]=i;
    TR1 tr1(n),tr2(m);
    int s=0;
    for(int i=1;i<=m;i++){
        if(!st[a[i]])tr1.add(a[i],1),s++;
        ans1[a[i]]=1;
        tr2.add(last[a[i]],-1);
        tr2.add(i,1);
        if(!st[a[i]]){
            ans2[a[i]]=max(ans2[a[i]],s-tr1.sum(a[i])+a[i]);
            st[a[i]]=1;
        }else {
            ans2[a[i]]=max(ans2[a[i]],1+tr2.query(last[a[i]]+1,i-1));
        }
        last[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(!st[i]) ans2[i]=max(ans2[i],s-tr1.sum(i)+i);
        else ans2[i]=max(ans2[i],tr2.query(last[i]+1,m)+1);
    }
    for(int i=1;i<=n;i++)cout<<ans1[i]<<" "<<ans2[i]<<endl;
}
void fast(){
    ios::sync_with_stdio( false);
    cin.tie(0),cout.tie(0);
}
signed main() {
    fast();
    int t = 1;
//    cin>>t;
    while(t--)solve();
}
```
