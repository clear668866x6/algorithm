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
int w[N];
int dfn[N],tmd;
int siz[N],fat[N];
VI g[N];
int son[N],dep[N],top[N],tr[N<<2];

void modify(int u,int v){
    for(tr[u+=n]=v;u>1;u>>=1)tr[u>>1]=max(tr[u],tr[u^1]);
}

int query(int l,int r){
    int res=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1)res=max(res,tr[l++]);
        if(r&1)res=max(res,tr[--r]);
    }
    return res;
}

void dfs1(int u,int fa){
    dep[u]=dep[fa]+1;
    siz[u]=1;
    fat[u]=fa;
    for(auto& j:g[u]){
        if(j==fa)continue;
        dfs1(j,u);
        siz[u]+=siz[j];
        if(siz[son[u]]<siz[j])son[u]=j;
    }
}

void dfs2(int u,int t){
    dfn[u]=++tmd,top[u]=t;
    modify(dfn[u],w[u]);
    if(son[u])dfs2(son[u],t);

    for(auto& j:g[u]){
        if(j==fat[u]||j==son[u])continue;
        dfs2(j,j);
    }
}

int query_path(int a,int b){
    int res=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]])swap(a,b);
        res=max(res,query(dfn[top[a]],dfn[a]+1));
        a=fat[top[a]];
    }
    if(dep[a]>dep[b])swap(a,b);
    res=max(res,query(dfn[a],dfn[b]+1));    
    return res;
}

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>w[i];

    FOR(i,2,n){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    dfs1(1,0);
    dfs2(1,1);

    while(m--){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            modify(dfn[x],y);
        }else{
            cout<<query_path(x,y)<<' ';
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