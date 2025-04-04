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

int n,m,k;
int cl[N];
int g[N][N];
int ans;
//通过枚举每个点来做的，没想到

void dfs(int u){
    if(u==n+1){
        ans++;
        RE;
    }

    bool f=false;

    FOR(i,1,k){
        cl[u]=i;
        FOR(j,1,u){
            if(g[u][j]&&cl[u]==cl[j]){
                f=1;
                break;
            }
        }
        if(f){
            f=0;
        }else{
            dfs(u+1);
        }
    }
}

void solve() {
    cin>>n>>m>>k;

    FOR(i,1,m){
        int a,b;
        cin>>a>>b;
        g[a][b]=g[b][a]=1;
    }

    dfs(1);

    cout<<ans;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}