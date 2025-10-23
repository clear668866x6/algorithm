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
int a[N],b[N];
int f[N];
VI g[N];

void dfs(int u,int color){
    f[u]=color;

    for(auto& j:g[u]){
        if(f[j]==-1){
            dfs(j,color^1);
        }else if(f[j]==f[u]){
            No;
            exit(0);
        }
    }
}

void solve() {
    cin>>n>>m;

    FOR(i,1,m)cin>>a[i];
    FOR(i,1,m)cin>>b[i];

    memset(f,-1,sizeof f);

    FOR(i,1,m){
        g[a[i]].emplace_back(b[i]);
        g[b[i]].emplace_back(a[i]);
    }

    FOR(i,1,n){
        if(f[i]==-1){
            dfs(i,0);
        }
    }
    Yes;
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}