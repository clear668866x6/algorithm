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
map<VI,int>mp,vis;

void solve() {
    cin>>n>>m;
    vector<vector<int>>w(n+1);
    FOR(i,1,n){
        VI res(m);
        for(auto& x:res)cin>>x;
        mp[res]++;
        for(auto x:res)w[i].emplace_back(x);
    }

    vector<vector<int>> ans(mp.sz+1);
    int cnt=0;
    FOR(i,1,n){
        if(vis[w[i]])continue;
        ans[++cnt].pb(mp[w[i]]);

        FOR(j,0,w[i].sz-1)ans[cnt].pb(w[i][j]);

        vis[w[i]]=1;
    }

    sort(ans.begin()+1,ans.end(),[&](VI a,VI b){
        if(a[0]==b[0])return a<b;
        return a[0]>b[0];
    });
    cout<<cnt<<endl;

    FOR(i,1,cnt){
        FOR(j,0,ans[i].sz-1){
            cout<<ans[i][j]<<" \n"[j==ans[i].sz-1];
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