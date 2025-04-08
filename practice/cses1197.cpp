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
 
int n,m;
vector<array<int,3>>e;
VI g[N],f[N];
int d[N];
bool vis1[N],vis2[N],vis3[N];
int pre[N];
 
void dfs(int u){
    if(vis1[u])RE;
    vis1[u]=1;
 
    for(auto& j:g[u]){
        dfs(j);
    }
}
 
void dfs2(int u){
    if(vis2[u])RE;
    vis2[u]=1;
 
    for(auto& j:f[u]){
        dfs2(j);
    }
}
 
void dfs3(int u){
    if(vis3[u]){
        cout<<u<<" ";
        RE;
    }
    vis3[u]=1;
    dfs3(pre[u]);
    cout<<u<<' ';
}
 
void solve() {
    cin>>n>>m;
 
    FOR(i,2,n)d[i]=1e18;
 
    FOR(i,1,m){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].emplace_back(b);
        f[b].emplace_back(a);
        e.pb({a,b,c});
    }
 
    int f=0;
    FOR(i,1,n){
        f=0;
        for(auto [a,b,w]:e){
            if(d[b]>d[a]+w){
                d[b]=d[a]+w;
                pre[b]=a;
                f=b;
            }
        }
    }
 
    if(!f){
        NO;
        RE;
    }
 
    YES;
 
    FOR(i,1,n)f=pre[f];
 
    VI ans;
 
    for(int x=f;;x=pre[x]){
        ans.pb(x);
        if(x==f&&ans.sz>1)break;
    }
    reverse(ALL(ans));
 
    for(auto x:ans)cout<<x<<' ';
 
}
 
signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}
