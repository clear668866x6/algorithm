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
VI g[N];
int stk[N],top,cnt;
bool in_stk[N];
int tmd,dfn[N],low[N];
int w[N];

void targin(int u){
    dfn[u]=low[u]=++tmd;
    stk[++top]=u,in_stk[u]=1;

    for(auto& j:g[u]){
        if(!dfn[j]){
            targin(j);
            low[u]=min(low[u],low[j]);
        }else if(in_stk[j]){
            low[u]=min(low[u],dfn[j]);
        }
    }

    if(dfn[u]==low[u]){
        int y;
        cnt++;
        do{
            y=stk[top--];
            in_stk[y]=false;
            w[y]=cnt;
        }while(y!=u);
    }

}

void solve() {
    cin>>n>>m;

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

    cout<<cnt<<endl;

    FOR(i,1,n){
        cout<<w[i]<<" \n"[i==n];
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}