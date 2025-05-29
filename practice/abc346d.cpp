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
string s;
int pre1[N],pre2[N];
void solve() {
    cin>>n>>s;

    FOR(i,1,n)cin>>w[i];

    s=' '+s;

    FOR(i,1,n){
        if(i&1){
            pre1[i]=pre1[i-1]+(s[i]=='0')*w[i];
            pre2[i]=pre2[i-1]+(s[i]=='1')*w[i];
        }else{
            pre1[i]=pre1[i-1]+(s[i]=='1')*w[i];
            pre2[i]=pre2[i-1]+(s[i]=='0')*w[i];
        }
    }

    int ans=1e18;

    FOR(i,2,n){
        int t1=(s[i]=='0')*w[i]+(s[i-1]=='0')*w[i-1];
        if(i&1){
            ans=min(ans,t1+pre1[n]-pre1[i]+pre2[i-2]);
        }else{
            ans=min(ans,t1+pre2[n]-pre2[i]+pre1[i-2]);
        }
        int t2=(s[i]=='1')*w[i]+(s[i-1]=='1')*w[i-1];
        if(i&1){
            ans=min(ans,t2+pre2[n]-pre2[i]+pre1[i-2]);
        }else{
            ans=min(ans,t2+pre1[n]-pre1[i]+pre2[i-2]);
        }
    }
    cout<<ans<<endl;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}