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
constexpr int N = 4e5 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n;
int a[N],b[N],c[N];
int d[N],cnt;
int f[N];
VPII w[N];

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>a[i]>>b[i]>>c[i];

    VI d;

    FOR(i,1,n){
        d.pb(a[i]);
        d.pb(b[i]);
    }

    sort(ALL(d));
    d.erase(unique(ALL(d)),d.end());

    FOR(i,1,n){
        a[i]=lower_bound(ALL(d),a[i])-d.begin()+1;
        b[i]=lower_bound(ALL(d),b[i])-d.begin()+1;
        w[b[i]].emplace_back(a[i],c[i]);
    }

    FOR(i,1,d.sz){
        f[i]=f[i-1];
        for(auto [x,v]:w[i]){
            f[i]=max(f[i],f[x-1]+v);
        }
    }
    cout<<f[d.sz];

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}