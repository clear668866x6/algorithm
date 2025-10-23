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

int n,m,k;

void solve() {
    cin>>n>>m>>k;

    vector<vector<char>>s(n+1,vector<char>(m+1,0));

    FOR(i,1,n){
        FOR(j,1,m){
            cin>>s[i][j];
        }
    }

    VII s1(n+1,VI(m+1,0)),s2(n+1,VI(m+1,0)),s3(n+1,VI(m+1,0)),s4(n+1,VI(m+1,0));

    FOR(i,1,n){
        FOR(j,1,m){
            s1[i][j]=s1[i][j-1]+(s[i][j]=='x');
            s3[i][j]=s3[i][j-1]+(s[i][j]=='.');
        }
    }

    FOR(i,1,n){
        FOR(j,1,m){
            s2[i][j]=s2[i-1][j]+(s[i][j]=='x');
            s4[i][j]=s4[i-1][j]+(s[i][j]=='.');
        }
    }

    int ans=1e18;

    FOR(i,1,n){
        FOR(j,1,m-k+1){
            if(s1[i][j+k-1]-s1[i][j-1]==0)ans=min(ans,s3[i][j+k-1]-s3[i][j-1]);
        }
    }

    FOR(i,1,n-k+1){
        FOR(j,1,m){
            if(s2[i+k-1][j]-s2[i-1][j]==0)ans=min(ans,s4[i+k-1][j]-s4[i-1][j]);
        }
    }

    if(ans==1e18)ans=-1;

    cout<<ans;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}