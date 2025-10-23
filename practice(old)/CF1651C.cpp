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

int n,a[N],b[N];

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>a[i];
    FOR(i,1,n)cin>>b[i];

    int ans=0;

    int v1=1e18,v2=1e18,v3=1e18,v4=1e18;

    FOR(i,1,n){
        v1=min(v1,abs(a[1]-b[i]));
        v2=min(v2,abs(a[n]-b[i]));
    }

    FOR(i,1,n){
        v3=min(v3,abs(b[1]-a[i]));
        v4=min(v4,abs(b[n]-a[i]));
    }

    ans=min(abs(a[1]-b[1])+abs(a[n]-b[n]),abs(a[1]-b[n])+abs(a[n]-b[1]));

    ans=min({ans,
        v1+v2+v3+v4,
        abs(a[1]-b[1])+v2+v4,
        abs(a[1]-b[n])+v2+v3,
        abs(a[n]-b[1])+v1+v4,
        abs(a[n]-b[n])+v1+v3
    });

    cout<<ans<<endl;


}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}