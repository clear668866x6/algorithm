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
constexpr int N = 1e3 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,m;
int w[N][N];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

void solve() {
    cin>>n>>m;

    FOR(i,1,n){
        FOR(j,1,m){
            cin>>w[i][j];
        }
    }

    vector<vector<bool>>vis(n+1,vector<bool>(m+1,0));

    int ans=0;

    function<int(int,int)> bfs=[&](int x,int y){
        int cnt=0;

        queue<PII>q;

        q.push({x,y});

        while(q.sz){
            auto [x,y]=q.front();
            q.pop();

            cnt+=w[x][y];

            FOR(i,0,3){
                int a=dx[i]+x,b=dy[i]+y;
                if(a<1||b<1||a>n||b>m||vis[a][b]||w[a][b]==0)continue;
                vis[a][b]=1;
                q.push({a,b});
            }
        }

        return cnt;
    };

    FOR(i,1,n){
        FOR(j,1,m){
            if(!vis[i][j]&&w[i][j]){
                vis[i][j]=1;
                ans=max(ans,bfs(i,j));
            }
        }
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