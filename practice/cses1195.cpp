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
VPII g[N];
int d[N][2];
bool vis[N][2];

void solve() {
    cin>>n>>m;

    FOR(i,1,m){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].emplace_back(b,c);
    }

    FOR(i,1,n){
        FOR(j,0,1){
            d[i][j]=1e18;
        }
    }

    d[1][0]=0;

    priority_queue<TII,vector<TII>,greater<TII>>q;

    q.push({0,1,0});

    while(q.sz){
        auto [x,ver,type]=q.top();
        q.pop();

        if(vis[ver][type])continue;
        vis[ver][type]=1;

        for(auto& [j,w]:g[ver]){
            if(d[j][0]>d[ver][0]+w){
                d[j][0]=d[ver][0]+w;
                q.push({d[j][0],j,0});
            }
            if(d[j][1]>d[ver][1]+w){
                d[j][1]=d[ver][1]+w;
                q.push({d[j][1],j,1});
            }
            if(d[j][1]>d[ver][0]+w/2){
                d[j][1]=d[ver][0]+w/2;
                q.push({d[j][1],j,1});
            }
        }
    }

    cout<<min(d[n][0],d[n][1]);

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}