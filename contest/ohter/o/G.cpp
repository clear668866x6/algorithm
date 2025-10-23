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

int n,c[N];
VPII g[N];

double check(int u,int fa,double x){
    double ans=0;
    for(auto [j,w]:g[u]){
        if(j==fa)continue;
        ans+=max(0.0,check(j,u,x)+c[j]-x*w);
    }
    return ans;
}

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>c[i];

    FOR(i,1,n){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].emplace_back(b,2*c);
        g[b].emplace_back(a,2*c);
    }

    double l=0,r=1e10;

    while(r-l>1e-6){
        double mid=(l+r)/2;
        if(check(0,-1,mid)>0)l=mid;
        else r=mid;
    }
    cout<<l;
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}