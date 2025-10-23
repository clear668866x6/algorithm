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

int n,m,w[N];

void solve() {
    cin>>n;

    int ans=0,t=1e18;

    VPII res;

    FOR(i,1,n){
        cin>>m;
        int mi1=1e18,mi2=1e18;
        FOR(j,1,m){
            cin>>w[j];
            if(mi1>w[j]){
                mi2=mi1;
                mi1=w[j];
            }else if(mi2>w[j]){
                mi2=w[j];
            }
        }
        res.pb({mi2,mi1});
        t=min(t,mi1);
    }

    sort(ALL(res));

    FOR(i,1,res.sz-1){
        ans+=res[i].fi;
    }
    
    cout<<ans+t<<endl;
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}