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

int n,m,v,ex,ey;
int a[N][N],b[N][N];
int ans=1e18;

int dfs(int u,int x,int y,int p){
    if(x==ex&&y==ey)return p;
    if(u>n*m){
        return 1e18;
    }

    return dfs(u+1,a[x][y],b[x][y],p+abs(a[x][y]-x)*v);
}

void solve() {
    cin>>n>>m>>v>>ex>>ey;

    FOR(i,1,n){
        FOR(j,1,m){
            cin>>a[i][j]>>b[i][j];
        }
    }

    FOR(i,1,m){
        ans=min(ans,dfs(1,1,i,0));
    }

    if(ans==1e18)cout<<"impossible"<<endl;
    else cout<<ans<<endl;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}