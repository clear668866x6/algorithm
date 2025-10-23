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
template<class T>using V=vector<T>;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,m,k;
VPII g[N];

void solve() {
    cin>>n>>m>>k;
    
    V<VI>d(m+1);

    FOR(i,1,m){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].emplace_back(b,c);
    }

    priority_queue<array<int,2>,V<array<int,2>>,greater<array<int,2>>>q;

    q.push({0,1});

    while(q.sz){
        auto u=q.top();
        q.pop();

        if(d[u[1]].sz==k)continue;
        d[u[1]].pb(u[0]);
        for(auto& [j,w]:g[u[1]]){
            q.push({u[0]+w,j});
        }
    }

    for(auto x:d[n]) cout<<x<<' ';

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}