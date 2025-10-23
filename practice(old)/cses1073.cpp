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

int n,tr[N],w[N],f[N],b[N];

void add(int x,int c){
    for(int i=x;i<N;i+=lowbit(i))tr[i]=max(tr[i],c);
}

int query(int x){
    int res=0;
    for(int i=x;i;i-=lowbit(i))res=max(res,tr[i]);
    return res;
}

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>w[i];

    FOR(i,1,n)b[i]=w[i];

    sort(b+1,b+1+n);

    FOR(i,1,n)w[i]=lower_bound(b+1,b+1+n,w[i])-b;

    int ans=0;

    FOR(i,1,n){
        f[i]=query(w[i])+1;
        add(w[i],f[i]);
        ans=max(ans,f[i]);
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