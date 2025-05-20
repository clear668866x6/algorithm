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
bool vis[N];

void solve() {
    cin>>n>>m;

    FOR(i,1,m){
        int a,b;
        cin>>a>>b;
        if(b==1)b=n+1;
        g[a].emplace_back(b);
    }

    priority_queue<PII,VPII,greater<PII>>q;
    q.push({0,1});
    VI d(n+2,1e18);
    d[1]=0;
    int cnt=0;
    while(q.sz){
        int ver=q.top().se;
        q.pop();

        if(vis[ver])continue;
        if(ver==1)cnt++;
        if(cnt==2)break;
        if(ver!=1)vis[ver]=1;
        for(auto& j:g[ver]){
            if(!vis[j]&&d[j]>d[ver]+1){
                d[j]=d[ver]+1;
                q.push({d[j],j});
            }
        }
    }

    if(d[n+1]==1e18)d[n+1]=-1;

    cout<<(d[n+1]);

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}