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

int n,k,m;
int w[N],pre[N];
//错误贪心：把所有数都删掉，为什么是错的，因为可能m很大，但k很小。

void solve() {
    cin>>n>>k>>m;

    FOR(i,1,n)cin>>w[i];

    sort(w+1,w+1+n);

    double ans=0;

    if(n==1){
        ans=w[1];
        cout<<fixed<<setprecision(12)<<ans+min(k,m)<<endl;
        RE;
    }

    FOR(i,1,n){
        pre[i]=pre[i-1]+w[i];
    }

    FOR(i,1,min(n,m+1)){
        int t=min(m-i+1,(n-i+1)*k);
        ans=max(ans,1.*(pre[n]-pre[i-1]+t)/(n-i+1));
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