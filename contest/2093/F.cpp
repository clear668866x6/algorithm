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
constexpr int N = 500 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,m;
string s[N][N];
string a[N];

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>a[i];

    FOR(i,1,m){
        FOR(j,1,n){
            cin>>s[i][j];
        }
    }

    int ans=0,mx=0;

    vector<bool>vis(n+1,0);

    FOR(i,1,m){
        int cnt=0;
        FOR(j,1,n){
            if(s[i][j]==a[j])vis[j]=1,cnt++;
        }
        mx=max(mx,cnt);
    }

    FOR(i,1,n){
        if(!vis[i]){
            cout<<-1<<endl;
            RE;
        }
    }

    cout<<(n+(n-mx)*2)<<endl;

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}