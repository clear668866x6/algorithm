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

int n,q;
VI g[N];
int dep[N],f[N][22];

void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    f[u][0]=fa;

    FOR(i,1,20)f[u][i]=f[f[u][i-1]][i-1];

    for(auto& j:g[u]){
        if(j==fa)continue;
        dfs(j,u);
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);

    FORD(i,0,20){
        if(dep[f[x][i]]>=dep[y]){
            x=f[x][i];
        }
    }

    if(x==y)return x;

    FORD(i,0,20){
        if(f[x][i]!=f[y][i]){
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}

void solve() {
    cin>>n>>q;

    FOR(i,2,n){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    dfs(1,0);

    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<(dep[a]+dep[b]-2*dep[lca(a,b)])<<endl;
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}