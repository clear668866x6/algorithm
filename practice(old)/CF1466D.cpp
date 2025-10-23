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

int n,w[N];

void solve() {
    cin>>n;

    int ans=0;

    FOR(i,1,n)cin>>w[i],ans+=w[i];

    vector<vector<int>>g(n+1);

    FOR(i,1,n-1){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    VI p;

    FOR(i,1,n){
        int t=g[i].sz;
        t--;
        while(t){
            p.pb(w[i]);
            t--;
        }
    }

    sort(ALL(p),greater());

    cout<<ans<<' ';

    FOR(i,0,n-3){
        ans+=p[i];
        cout<<ans<<' ';
    }
    cout<<endl;

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}