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

int f[N];
VI g[N];
int n;
int siz[N];
int ans[N];

void dfs1(int u,int fa,int dep){
    ans[1]+=dep;
    siz[u]=1;
    for(auto& j:g[u]){
        if(j==fa)continue;
        dfs1(j,u,dep+1);
        siz[u]+=siz[j];
    }
}

void dfs2(int u,int fa){
    for(auto& j:g[u]){
        if(j==fa)continue;
        ans[j]=ans[u]+n-2*siz[j];
        dfs2(j,u);
    }
}

void solve() {
    cin>>n;
    
    FOR(i,2,n){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    dfs1(1,0,0);
    dfs2(1,0);

    FOR(i,1,n)cout<<ans[i]<<" ";
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}