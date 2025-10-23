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
int w[N],f[N][32];
int dep[N];
bool vis[N];

void dfs(int u){
    if(vis[u])return;
    vis[u]=1;
    dfs(f[u][0]);
    dep[u]=dep[f[u][0]]+1;
}

int query(int x,int k){
    if(k<=0)return x;
    FOR(i,0,30){
        if((k>>i)&1){
            x=f[x][i];
        }
    }
    return x;
}

void solve() {
    cin>>n>>q;

    FOR(i,1,n)cin>>w[i];

    FOR(i,1,n)f[i][0]=w[i];

    FOR(j,1,30){
        FOR(i,1,n){
            f[i][j]=f[f[i][j-1]][j-1];
        }
    }

    FOR(i,1,n){
        if(!vis[i]){
            dfs(i);
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b;
        int rt=query(a,dep[a]);
        if(query(a,dep[a]-dep[b])==b){
            cout<<dep[a]-dep[b]<<endl;
        }else if(query(rt,dep[rt]-dep[b])==b){
            cout<<dep[a]+dep[rt]-dep[b]<<endl;
        }else{
            cout<<-1<<endl;
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