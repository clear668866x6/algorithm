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

int n,k;
struct E{
    int w,a;
    bool operator<(const E& t)const{
        return w<t.w;
    }
}w[N];

void solve() {
    cin>>n>>k;

    FOR(i,1,n)cin>>w[i].w;
    FOR(i,1,n)cin>>w[i].a;

    sort(w+1,w+1+n);

    VI suf(n+2,1e18);

    FORD(i,1,n){
        suf[i]=min(suf[i+1],w[i].a);
    }

    int t=k;

    while(1){
        int id=upper_bound(w+1,w+1+n,E{t,-1})-w-1;
        if(k<=0&&id<n){
            No;
            RE;
        }
        if(id>=n){
            Yes;
            RE;
        }
        k-=suf[id+1];
        t+=k;
    }

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}