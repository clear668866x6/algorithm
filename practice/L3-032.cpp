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
constexpr int mod = 1e9+7;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,rt;
VI g[N];
int siz[N];
int tr[N],a1,a2;

void add(int x,int c){
    for(int i=x;i<N;i+=lowbit(i))tr[i]+=c;
}

int query(int x){
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=tr[i];
    return res;
}

void dfs(int u,int fa){
    add(u,1);
    a1=(a1+query(n)-query(u))%mod;
    siz[u]=1;
    for(auto& j:g[u]){
        if(j==fa)continue;
        siz[j]+=siz[u];
        dfs(j,u);
    }

    a2=(a2+n-query(u)-siz[u]+1)%mod;
    add(u,-1);
}

void solve() {
    cin>>n>>rt;

    FOR(i,1,n-1){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    dfs(rt,0);

    
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}