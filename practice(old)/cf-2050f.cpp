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

namespace ST{
    int f[N][22],s[N];

    void init(int n){
        FOR(j,0,20){
            for(int i=1;i+(1<<j)-1<=n;i++){
                if(!j)f[i][j]=s[i];
                else f[i][j]=__gcd(f[i][j-1],f[i+(1<<j-1)][j-1]);
            }
        }
    }

    int query(int l,int r){
        int len=__lg(r-l+1);
        return __gcd(f[l][len],f[r-(1<<len)+1][len]);
    }
}

using namespace ST;

int n,m;
int w[N];

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>w[i];

    FOR(i,1,n-1)s[i]=abs(w[i+1]-w[i]);

    init(n-1);

    while(m--){
        int l,r;
        cin>>l>>r;
        if(l==r)cout<<0<<' ';
        else cout<<query(l,r-1)<<' ';
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