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

int n,m;
int a[N],b[N];
int pre[N],suf[N];

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>a[i];
    FOR(i,1,m)cin>>b[i];

    b[0]=b[m+1]=1e18;
    pre[0]=0;
    int r=1;
    FOR(i,1,n){
        pre[i]=pre[i-1]+(a[i]>=b[pre[i-1]+1]);
    }
    suf[n+1]=0;
    FORD(i,1,n){
        suf[i]=suf[i+1]+(a[i]>=b[m-suf[i+1]]);
    }

    int ans=1e18;

    if(pre[n]==m){
        cout<<0<<endl;
        RE;
    }

    FOR(i,0,n){
        if(pre[i]+suf[i+1]>=m-1){
            ans=min(ans,b[pre[i]+1]);
        }
    }
    if(ans==1e18)cout<<-1<<endl;
    else cout<<ans<<endl;
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}