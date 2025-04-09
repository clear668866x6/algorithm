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
int x[N],r[N];

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>x[i];

    FOR(i,1,n)cin>>r[i];

    int ans=0;

    map<int,int>vis;

    map<int,int>mx;

    FOR(i,1,n){
        FOR(j,x[i]-r[i],x[i]+r[i]){
            int y=r[i]*r[i]-(j-x[i])*(j-x[i]);
            mx[j]=max(mx[j],(int)sqrt(y));
        }
    }

    FOR(i,1,n){
        FOR(j,x[i]-r[i],x[i]+r[i]){
            if(vis[j])continue;
            vis[j]=1;
            ans+=2*mx[j]+1;
        }
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