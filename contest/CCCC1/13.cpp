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

int n,m,sx,sy;
VPII g[N];
int d[N],vis[N],sum[N],c[N];

void solve() {
    cin>>n>>m>>sx>>sy;

    FOR(i,1,n)cin>>c[i];

    FOR(i,1,m){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }

    priority_queue<TII,vector<TII>,greater<TII>>q;

    FOR(i,1,n){
        d[i]=1e18;
    }

    q.push({0,0,sx});
    d[sx]=0;
    c[sx]=c[sy]=0;

    while(q.sz){
        auto [a,e,ver]=q.top();
        q.pop();

        if(vis[ver])continue;
        vis[ver]=1;

        for(auto& [j,w]:g[ver]){
            if(d[j]>d[ver]+w){
                d[j]=d[ver]+w;
                sum[j]=max(e,c[j]);
                q.push({d[j],sum[j],j});
            }else if(d[j]==d[ver]+w&&sum[j]>e){
                sum[j]=min(sum[j],max(e,c[j]));
                q.push({d[j],sum[j],j});
            }
        }
    }

    if(d[sy]==1e18){
        cout<<"Impossible";
    }else{
        cout<<d[sy]<<' '<<sum[sy];
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}