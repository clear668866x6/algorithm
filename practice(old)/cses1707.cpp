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
VPII w;

int bfs(int x,int y){
    
    queue<int>q;
    VI d(n+1,1e18);
    q.push(x);
    d[x]=1;
    while(q.sz){
        int t=q.front();
        q.pop();

        for(auto& j:g[t]){
            if((x==t&&y==j)||(d[j]<=d[t]+1))continue;
            d[j]=d[t]+1;
            if(j==y)return d[j];
            q.push(j);
        }
    }
    return d[y];
}

void solve() {
    cin>>n>>m;

    FOR(i,1,m){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        w.pb({a,b});
    }

    int ans=1e18;

    FOR(i,0,m-1){
        ans=min(ans,bfs(w[i].fi,w[i].se));
    }

    if(ans==1e18)ans=-1;
    
    cout<<ans;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}