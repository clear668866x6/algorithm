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

int n,k;
int c[N];
int p[N];
VI g[N];
int d[N];
int f[N];

int dfs(int u){
    if(f[u]!=-1)return f[u];
    f[u]=c[u];

    int sum=0;

    for(auto& j:g[u]){
        sum+=dfs(j);
    }
    if(!g[u].sz)sum=1e18;
    f[u]=min(f[u],sum);
    return f[u];
}

void solve() {
    cin>>n>>k;
    
    FOR(i,1,n)cin>>c[i];
    
    FOR(i,1,n)g[i].clear(),f[i]=-1;

    FOR(i,1,k){
        int x;
        cin>>x;
        f[x]=0;
    }
    
    FOR(i,1,n){
        int t;
        cin>>t;
        while(t--){
            int x;
            cin>>x;
            g[i].emplace_back(x);
        }
    }

    FOR(i,1,n){
        cout<<dfs(i)<<" \n"[i==n];
    }
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}