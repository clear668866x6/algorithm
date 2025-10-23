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

int n,m;
int f[N][N];

void solve() {
    cin>>n>>m;

    FOR(i,1,n){
        FOR(j,1,m){
            f[i][j]=1e18;
        }
    }

    FOR(i,1,n){
        f[i][1]=i-1;
    }

    FOR(i,1,m){
        f[1][i]=i-1;
    }

    FOR(i,1,n){
        FOR(j,1,m){

            if(i==j){
                f[i][j]=0;
                continue;
            }

            FOR(k,1,i/2){
                f[i][j]=min(f[i][j],f[k][j]+f[i-k][j]+1);
            }

            FOR(k,1,j/2){
                f[i][j]=min(f[i][j],f[i][k]+f[i][j-k]+1);
            }
        }
    }

    cout<<f[n][m];

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}