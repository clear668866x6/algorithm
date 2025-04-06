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

void solve() {
    cin>>n>>m;

    VI prev(1<<n,0);

    prev[0]=1;

    FOR(i,0,m-1){
        FOR(j,0,n-1){
            VI f(1<<n,0);
            FOR(k,0,(1<<n)-1){
                if(k>>j&1){
                    f[k^(1<<j)]=(f[k^(1<<j)]+prev[k])%mod;
                }else{
                    f[k|(1<<j)]=(f[k|(1<<j)]+prev[k])%mod;
                    if(j+1<n&&!(k>>(j+1)&1)){
                        f[k|(1<<(j+1))]=(f[k|(1<<(j+1))]+prev[k])%mod;
                    }
                }
            }
            prev=f;
        }
    }
    cout<<prev[0];
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}