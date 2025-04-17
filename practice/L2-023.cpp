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

int n,m,k;
VI g[N];
int c[N];
bool f;
bool vis[N];

void dfs(int u,int fa){
    if(f)RE;
    if(vis[u])RE;
    vis[u]=1;

    for(auto& j:g[u]){
        if(j==fa)continue;
        if(c[j]==c[u]){
            f=1;
        }
        dfs(j,u);
    }
}

void solve() {
    cin>>n>>m>>k;

    FOR(i,1,m){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    int q;
    cin>>q;

    while(q--){
        f=0;
        set<int>s;
        FOR(i,1,n)cin>>c[i],s.insert(c[i]),vis[i]=0;
        if(s.sz!=k){
            No;
        }else{
            FOR(i,1,n){
                dfs(i,0);
            }
            if(f){
                No;
            }else{
                Yes;
            }
        }
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}