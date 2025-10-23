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
constexpr int N = 3e5 + 10;
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

    vector<vector<int>> g(n+1),G(n+1);

    FOR(i,2,n){
        int x;
        cin>>x;
        g[x].emplace_back(i);
    }

    function<void(int,int)>dfs=[&](int u,int dep){
        G[dep].emplace_back(u);
        for(auto& j:g[u]){
            dfs(j,dep+1);
        }
    };

    dfs(1,1);

    VI f1(n+n,0),f2(n+n,0);
    f1[1]=f2[1]=1;

    FOR(i,2,n){
        for(auto& j:G[i]){
            (f1[j]+=f2[i-1])%=mod;
            for(auto& k:g[j]){
                f1[k]=((f1[k]-f1[j])%mod+mod)%mod;
            }
            (f2[i]+=f1[j])%=mod;
        }
    }

    int ans=0;

    FOR(i,1,n){
        ans=(ans+f1[i])%mod;
    }
    cout<<ans<<endl;

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}