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
constexpr int N = 5e4 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,m,q;
VI g[N],ng[N];
int low[N],dfn[N],tmd;
int stk[N],top;
bool in_stk[N];
int din[N];
int id[N],scc_cnt;
bitset<N>d[N];

void targin(int u){
    low[u]=dfn[u]=++tmd;
    stk[++top]=u,in_stk[u]=true;

    for(auto& j:g[u]){
        if(!dfn[j]){
            targin(j);
            low[u]=min(low[u],low[j]);
        }else if(in_stk[j]){
            low[u]=min(low[u],dfn[j]);
        }
    }
    if(low[u]==dfn[u]){
        int y;
        scc_cnt++;
        do{
            y=stk[top--];
            in_stk[y]=false;
            id[y]=scc_cnt;
            d[scc_cnt].set(y);
        }while(y!=u);
    }
}

void tops(){
    queue<int>q;

    FOR(i,1,scc_cnt){
        if(!din[i])q.push(i);
    }
    while(q.sz){
        int t=q.front();
        q.pop();
        sort(ALL(ng[t]));

        for(auto& j:ng[t]){
            --din[j];
            d[j]|=d[t];
            if(!din[j])q.push(j);
        }
    }
}

void solve() {
    cin>>n>>m>>q;

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
        for(auto j:g[i]){
            if(id[j]==id[i])continue;
            ng[id[j]].emplace_back(id[i]);
            din[id[i]]++;
        }
    }

    tops();

    while(q--){
        int x,y;
        cin>>x>>y;
        if(d[id[x]][y]){
            YES;
        }else{
            NO;
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