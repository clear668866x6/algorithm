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

int n,q;
string s,t;

void solve() {
    cin>>n>>q>>s>>t;

    s=' '+s;
    t=' '+t;

    vector<vector<int>>f(n+n,vector<int>(30,0)),g(n+n,vector<int>(30,0));

    FOR(i,1,n){
        FOR(j,0,25){
            if((s[i]-'a')==j){
                f[i][j]=f[i-1][j]+1;
            }else{
                f[i][j]=f[i-1][j];
            }
            if((t[i]-'a')==j){
                g[i][j]=g[i-1][j]+1;
            }else{
                g[i][j]=g[i-1][j];
            }
        }
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=0;
        FOR(i,0,25){
            ans+=abs(f[r][i]-f[l-1][i]-(g[r][i]-g[l-1][i]));
        }
        cout<<ans/2<<endl;
    }

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}