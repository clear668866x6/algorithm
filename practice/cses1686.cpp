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

//在一个强连通分量中，所有的金币能收集到
//缩点+dp

int n,m;
int w[N];
VI g[N],g2[N];
int dfn[N],low[N],tmd;
bool instk[N];
int top,stk[N];
int f[N];
int cnt;
int nw[N],id[N];

void targin(int u){
    low[u]=dfn[u]=++tmd;
    instk[u]=1;stk[++top]=u;

    for(auto& j:g[u]){
        if(!dfn[j]){
            targin(j);
            low[u]=min(low[u],low[j]);
        }else if(instk[j]){
            low[u]=min(low[u],dfn[j]);
        }
    }

    if(low[u]==dfn[u]){
        int y;
        cnt++;
        do{
            y=stk[top--];
            instk[y]=false;
            nw[cnt]+=w[y];
            id[y]=cnt;
        }while(y!=u);
    }
}

int dp(int u){
    if(f[u])return f[u];
    int res=0;

    for(auto& j:g2[u]){
        res=max(res,dp(j));
    }
    return f[u]=res+nw[u];
}

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>w[i];

    FOR(i,1,m){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
    }

    FOR(i,1,n){
        if(!dfn[i]){
            targin(i);
        }
    }

    FOR(i,1,n){
        for(auto& j:g[i]){
            if(id[j]!=id[i]){
                g2[id[i]].emplace_back(id[j]);
            }
        }
    }

    int ans=0;

    FOR(i,1,n){
        ans=max(ans,dp(i));
    }
    cout<<ans;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}