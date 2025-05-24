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
constexpr int N = 2e6 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,a[N],b[N];
int sum[N];
VI v;

int get1(int x){
    return lower_bound(ALL(v),x)-v.begin()+1;
}

int get2(int x){
    return upper_bound(ALL(v),x)-v.begin();
}

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>a[i],v.pb(a[i]);
    FOR(i,1,n)cin>>b[i];

    sort(ALL(v));
    v.erase(unique(ALL(v)),v.end());

    FOR(i,1,n){
        a[i]=get1(a[i]);
    }

    FOR(i,1,n){
        sum[i]=sum[i-1]+b[i];
    }

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l=get1(l),r=get2(r);
        cout<<(sum[r]-sum[l-1])<<endl;
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}