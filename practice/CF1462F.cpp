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

int n;
PII w[N];
//区间不相交的个数可以用二分做，也就是把左右端点都存下来。

void solve() {
    cin>>n;

    VI l(n),r(n);

    FOR(i,0,n-1){
        int a,b;
        cin>>a>>b;
        l[i]=a,r[i]=b;
        w[i]={a,b};
    }

    sort(ALL(l)),sort(ALL(r));

    int ans=1e18;
    
    FOR(i,0,n-1){
        int cnt=0;
        int t=upper_bound(ALL(l),w[i].se)-l.begin();
        cnt+=(n-t+1);
        t=lower_bound(ALL(r),w[i].fi)-r.begin();
        cnt+=(t-1);
        ans=min(ans,cnt);
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