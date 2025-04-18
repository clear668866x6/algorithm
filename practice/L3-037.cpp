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
constexpr int N = 100 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int w[N][N],n,m,Q;
int d[N][N];
bool vis[N][N];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int res[N*N];

void solve() {
    int x0,y0;
    cin>>n>>m;

    FOR(i,1,n){
        FOR(j,1,m){
            d[i][j]=1e18;
            cin>>w[i][j];
            if(w[i][j]==2)x0=i,y0=j;
        }
    }

    queue<TII>q;

    q.push({x0,y0,0});
    vis[x0][y0]=1;

    while(q.sz){
        auto [x,y,step]=q.front();
        q.pop();

        if(w[x][y]==1){
            d[x][y]=step;
        }

        FOR(i,0,3){
            int a=dx[i]+x,b=dy[i]+y;
            if(a<1||b<1||a>n||b>m||vis[a][b]||w[a][b]==0)continue;
            q.push({a,b,step+1});
            vis[a][b]=1;
        }        
    }

    cin>>Q;

    map<int,VI>mp;

    FOR(i,1,Q){
        int x,y;
        cin>>x>>y;
        res[i]=d[y][x];
    }

    FOR(i,1,Q){
        if(res[i]!=1e18)mp[res[i]].pb(i);
    }

    bool f=false;

    VI ans;

    for(auto [x,y]:mp){
        if(y.sz==1){
            f=1;
            cout<<y[0]<<' '<<x<<endl;
            RE;
        }
    }
    if(!f){
        cout<<"No winner.";
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}