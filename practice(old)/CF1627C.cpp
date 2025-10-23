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

int n;

void solve() {
    cin>>n;

    vector<VPII>g(n+1);

    FOR(i,2,n){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b,i);
        g[b].emplace_back(a,i);
    }

    bool f=0;
    VI ans(n+1,0);

    function<void(int,int,int)>dfs=[&](int u,int fa,int t){
        if(f)RE;
        if(u!=1&&g[u].sz>2){
            f=1;
            RE;
        }
        int cnt=0;
        for(auto [j,id]:g[u]){
            if(j==fa)continue;
            if(t==2) t=3;
            else t=2;
            ans[id]=t;
            dfs(j,u,t);
        }
    };

    if(g[1].sz>2){
        cout<<-1<<endl;
        RE;
    }

    dfs(1,0,2);
    
    if(f){
        cout<<-1<<endl;
    }else{
        FOR(i,2,n){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}