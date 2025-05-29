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

int n,w[N],pre[N];

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>w[i],pre[i]=pre[i-1]+w[i];

    int ans=-1e18,ansl=0,ansr=0,ansm=0;

    FOR(i,1,n){
        int mx1=-1e18,mx2=-1e18,p1=0,p2=0;
        FOR(j,1,i){
            int t=(pre[j-1])-(pre[i-1]-pre[j-1]);
            if(t>mx1){
                mx1=t;
                p1=j;
            }
        }

        FOR(j,i,n+1){
            int t=(pre[j-1]-pre[i-1])-(pre[n]-pre[j-1]);
            if(t>mx2){
                mx2=t;
                p2=j;
            }
        }
        // cout<<mx1<<' '<<mx2<<' '<<i<<' '<<ansl<<' '<<ansr<<endl;
        if(mx1+mx2>ans){
            ans=mx1+mx2;
            ansl=p1;
            ansm=i;
            ansr=p2;
        }
    }

    // cout<<ans<<endl;

    cout<<(ansl-1)<<' '<<(ansm-1)<<' '<<(ansr-1)<<endl;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}