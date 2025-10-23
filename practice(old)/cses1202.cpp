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
constexpr int mod = 1e9+7;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,m;
VPII g[N];
int dist[N],cnt[N],mx[N],mi[N];
bool vis[N];

void solve() {
    cin>>n>>m;

    FOR(i,1,m){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].emplace_back(b,c);
    }

    priority_queue<PII,VPII,greater<PII>>q;

    FOR(i,2,n){
        dist[i]=1e18;
    }
    cnt[1]=1;

    q.push({0,1});

    while(q.sz){
        int ver=q.top().se;
        q.pop();

        if(vis[ver])continue;
        vis[ver]=1;

        for(auto& [j,w]:g[ver]){
            if(dist[j]>dist[ver]+w){
                dist[j]=dist[ver]+w;
                cnt[j]=cnt[ver];
                mx[j]=mx[ver]+1;
                mi[j]=mi[ver]+1;
                q.push({dist[j],j});
            }else if(dist[j]==dist[ver]+w){
                cnt[j]=(cnt[j]+cnt[ver])%mod;
                mx[j]=max(mx[j],mx[ver]+1);
                mi[j]=min(mi[j],mi[ver]+1);
            }
        }
    }

    cout<<dist[n]<<' '<<cnt[n]<<' '<<mi[n]<<' '<<mx[n];
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}