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
constexpr int N = 4e5 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,m,dep[N],f[N][25],d[N][25];
struct E{
    int a,b,c,id;
    bool operator<(const E& t)const{
        return c<t.c;
    }
}w[N];
int p[N];
VPII g[N];

int find(int x){
    if(x!=p[x])p[x]=find(p[x]);
    return p[x];
}

void dfs(int u,int fa){

    FOR(i,1,20){
        f[u][i]=f[f[u][i-1]][i-1];
        d[u][i]=max(d[u][i-1],d[f[u][i-1]][i-1]);
    }

    for(auto& [j,c]:g[u]){
        if(j==fa)continue;
        dep[j]=dep[u]+1;
        f[j][0]=u;
        d[j][0]=c;
        dfs(j,u);
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);

    int ans=0;

    FORD(i,0,20){
        if(dep[f[x][i]]>=dep[y]){
            ans=max(ans,d[x][i]);
            x=f[x][i];
        }
    }

    if(x==y)return ans;

    FORD(i,0,20){
        if(f[x][i]!=f[y][i]){
            ans=max(ans,d[x][i]);
            ans=max(ans,d[y][i]);
            x=f[x][i];
            y=f[y][i];
        }
    }
    return max({ans,d[x][0],d[y][0]});
}

void solve() {
    cin>>n>>m;

    FOR(i,1,m){
        int a,b,c;
        cin>>a>>b>>c;
        w[i]={a,b,c,i};
    }

    sort(w+1,w+1+m);

    FOR(i,1,n)p[i]=i;

    int tot=0;

    FOR(i,1,m){
        int a=w[i].a,b=w[i].b,c=w[i].c;
        int pa=find(a),pb=find(b);
        if(pa!=pb){
            p[pa]=pb;
            g[pa].emplace_back(pb,c);
            g[pb].emplace_back(pa,c);
            tot+=c;
        }
    }

    dfs(1,0);

    sort(w+1,w+1+m,[&](E x,E y){
        return x.id<y.id;
    });

    FOR(i,1,m){
        int t=lca(w[i].a,w[i].b);
        cout<<(tot-t+w[i].c)<<endl;
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}