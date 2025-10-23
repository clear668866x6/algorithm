#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"
using PII = pair<int, int>;
using TII = tuple<int, int, int>;
#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define BSI basic_string<int>
#define BSPI basic_string<PII>
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define VI vector<int>
#define VII vector<vector<int>>
#define VPII vector<PII>
#define lowbit(x) ((x)&(-x))
#define RE return;
#define RET return true;
#define REF return false;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define fi first
#define se second
#define sz size()
constexpr int N = 2e5 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n;
int fac[N];
int ans=1e18;

void dfs(int u,int x,int y){
    if(u>15)RE;
    if(x>n)RE;

    ans=min(ans,__builtin_popcountll(n-x)+y);

    dfs(u+1,x+fac[u],y+1);
    dfs(u+1,x,y);
}

void init(){
    fac[0]=1;
    FOR(i,1,15){
        fac[i]=fac[i-1]*i;
    }    
}

void solve() {
    cin>>n;
    ans=1e18;

    dfs(3,0,0);//在二进制下，肯定是把2的米此方跟阶乘混合起来考虑。
    if(ans==1e18)cout<<-1<<endl;
    else cout<<ans<<endl;
}

signed main() {
    int Task = 1;
    init();
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}