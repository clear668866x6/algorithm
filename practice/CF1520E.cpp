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

void solve() {
    cin>>n>>s;
    
    VI cs;
    VI pre(n+2,0),suf(n+2,0),pres(n+2,0),sufs(n+2,0);
    s=' '+s;
 
    FOR(i,1,n){
        if(s[i]=='*'){
            pre[i]=pre[i-1]+1;
            pres[i]=pres[i-1]+i;
        }else{
            pre[i]=pre[i-1];
            pres[i]=pres[i-1];
        }
    }
    
    FORD(i,1,n){
        if(s[i]=='*'){
            suf[i]=suf[i+1]+1;
            sufs[i]=sufs[i+1]+i;
        }else{
            suf[i]=suf[i+1];
            sufs[i]=sufs[i+1];
        }
    }

    int ans=1e18;

    FOR(i,1,n){
        if(s[i]=='*'){
            int l=pre[i-1]*i-pres[i-1]-(1+pre[i-1])*(pre[i-1])/2;
            int r=sufs[i+1]-suf[i+1]*i-(1+suf[i+1])*suf[i+1]/2;
            ans=min(ans,l+r);
        }else{
            int l1=pre[i-1]*i-pres[i-1]-(1+pre[i-1])*(pre[i-1])/2;
            int l2=l1+pre[i-1];
            int r1=sufs[i+1]-suf[i+1]*i-(1+suf[i+1])*suf[i+1]/2;
            int r2=r1+suf[i+1];
            ans=min({ans,l1+r2,l2+r1});
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