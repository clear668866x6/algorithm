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
constexpr int N = 4e6 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,x;
int w[N];
int f[N][2];

void solve() {
    cin>>n>>x;

    map<int,int>mp;

    int mx=1e6;

    FOR(i,1,n)cin>>w[i],mp[w[i]]++;

    if(x==0){
        int ans=0;
        FOR(i,0,mx)ans+=max<int>(0,mp[i]-1);
        cout<<ans;
    }else{
        FOR(i,0,x-1)f[i][1]=mp[i];
        FOR(i,x,mx){
            f[i][0]=f[i-x][1];
            f[i][1]=min(f[i-x][0],f[i-x][1])+mp[i];
        }
        int ans=0;
        FOR(i,mx-x+1,mx)ans+=min(f[i][1],f[i][0]);
        cout<<ans;
    }    
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}