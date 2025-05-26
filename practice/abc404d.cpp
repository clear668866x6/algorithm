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
constexpr int N = 100 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,m;
int c[N];
VI b[N];
map<int,int>vis;
int ans=1e18;

void dfs(int u,int tot){
    if(u==n+1){
        bool f=false;
        FOR(i,1,m){
            if(vis[i]<2){
                f=1;
                break;
            }
        }
        if(!f){
            ans=min(ans,tot);
        }
        RE;
    }

    for(auto& j:b[u]) vis[j]++;
    dfs(u+1,tot+c[u]);
    for(auto& j:b[u]) vis[j]--;
    for(auto& j:b[u]) vis[j]+=2;
    dfs(u+1,tot+2*c[u]);
    for(auto& j:b[u]) vis[j]-=2;
    dfs(u+1,tot);

}

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>c[i];

    FOR(i,1,m){
        int k,x;
        cin>>k;
        while(k--){
            cin>>x;
            b[x].emplace_back(i);
        }
    }
    dfs(1,0);

    cout<<ans;
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}