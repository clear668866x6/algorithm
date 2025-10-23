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
string s;

void solve() {
    cin>>n;

    vector<vector<int>> g(n+1);

    FOR(i,2,n){
        int x;
        cin>>x;
        g[x].emplace_back(i);
        g[i].emplace_back(x);
    }

    cin>>s;

    s=' '+s;
    VI c1(n+1,0),c2(n+1,0);

    FOR(i,1,n){
        c1[i]=(s[i]=='W');
        c2[i]=(s[i]=='B');
    }

    int ans=0;


    function<void(int,int)>dfs=[&](int u,int fa){
        for(auto& j:g[u]){
            if(j==fa)continue;
            dfs(j,u);
            c1[u]+=c1[j];
            c2[u]+=c2[j];
        }
    };

    dfs(1,0);

    FOR(i,1,n){
        if(c1[i]==c2[i])ans++;
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