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
constexpr int N = 500 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,m,s,t;
int c[N];
vector<PII>g[N];
int dist[N];
int pre[N],cnt[N];
int sum[N];
bool vis[N];
VI ans;

void dfs(int u){
    if(u==s){
        ans.pb(u-1);
        RE;
    }
    dfs(pre[u]);
    ans.pb(u-1);
}

void solve() {
    cin>>n>>m>>s>>t;
    s++,t++;

    FOR(i,1,n)cin>>c[i];

    FOR(i,1,m){
        int a,b,c;
        cin>>a>>b>>c;
        a++,b++;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }

    priority_queue<PII,vector<PII>,greater<PII>>q;

    FOR(i,0,n+1)pre[i]=-1;

    FOR(i,0,n+1){
        dist[i]=1e18;
    }

    q.push({0,s});
    dist[s]=0;
    cnt[s]=1;
    sum[s]=c[s];

    while(q.sz){
        int ver=q.top().se;
        q.pop();

        if(vis[ver])continue;
        vis[ver]=1;

        for(auto& [j,w]:g[ver]){
            if(dist[j]>dist[ver]+w){
                dist[j]=dist[ver]+w;
                cnt[j]=cnt[ver];
                sum[j]=sum[ver]+c[j];
                pre[j]=ver;
                q.push({dist[j],j});
            }else if(dist[j]==dist[ver]+w){
                cnt[j]+=cnt[ver];
                if(sum[j]<sum[ver]+c[j]){
                    sum[j]=sum[ver]+c[j];
                    pre[j]=ver;
                }
                q.push({dist[j],j});
            }
        }
    }

    cout<<cnt[t]<<' '<<sum[t]<<endl;

    dfs(t);

    FOR(i,0,ans.sz-1){
        cout<<ans[i]<<" \n"[i==ans.sz-1];
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}