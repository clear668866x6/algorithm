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
string s;
int f[N][3];

void solve() {
    cin>>n>>s;

    s=' '+s;
    //0 R
    //1 P
    //2 S
    FOR(i,1,n){
        if(s[i]=='R'){
            f[i][1]=max(f[i-1][0],f[i-1][2])+1;
            f[i][0]=max(f[i-1][1],f[i-1][2]);
        }else if(s[i]=='P'){
            f[i][2]=max(f[i-1][0],f[i-1][1])+1;
            f[i][1]=max(f[i-1][0],f[i-1][2]);
        }else{
            f[i][0]=max(f[i-1][1],f[i-1][2])+1;
            f[i][2]=max(f[i-1][0],f[i-1][1]);
        }
    }

    int ans=0;

    FOR(i,0,2){
        ans=max(ans,f[n][i]);
    }
    cout<<ans;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}