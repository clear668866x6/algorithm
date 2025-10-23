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
constexpr int N = 3e5 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int x,y,z;
string s;
int f[N][2];

void solve() {
    cin>>x>>y>>z>>s;
    int n=s.sz;

    s=' '+s;

    FOR(i,0,n)f[i][0]=f[i][1]=1e18;

    f[0][0]=0;

    FOR(i,1,n){
        if(s[i]=='a'){
            f[i][0]=min(f[i-1][1]+z+min(x,y),f[i-1][0]+x);
            f[i][1]=min(f[i-1][1]+y,f[i-1][0]+z+min(x,y));
        }else{
            f[i][0]=min(f[i-1][1]+z+min(x,y),f[i-1][0]+y);
            f[i][1]=min(f[i-1][1]+x,f[i-1][0]+z+min(x,y));
        }
    }

    cout<<min(f[n][0],f[n][1])<<endl;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}