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
constexpr int N = 40 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,x;
int w[N];

VI calc(int l,int r){
    int len=r-l+1;

    VI ans;
    
    FOR(i,0,(1<<len)-1){
        int s=0;
        FOR(j,0,len-1){
            if(i>>j&1){
                s+=w[l+j];
            }
        }
        ans.pb(s);
    }
    return ans;
}

void solve() {
    cin>>n>>x;
    
    FOR(i,0,n-1)cin>>w[i];

    VI a=calc(0,n/2-1);
    VI b=calc(n/2,n-1);

    sort(ALL(a));
    sort(ALL(b));

    int ans=0;

    for(auto p:a){
        auto l=lower_bound(ALL(b),x-p);
        auto r=upper_bound(ALL(b),x-p);
        ans+=r-l;
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