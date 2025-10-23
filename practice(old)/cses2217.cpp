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

int n,m;
int w[N];
int loc[N],ans=1;

void work(int x,int y){
    if(w[x]>1&&loc[w[x]-1]<=y&&loc[w[x]-1]>loc[w[x]])ans--;
    if(w[x]<n&&loc[w[x]+1]<=y&&loc[w[x]]<loc[w[x]+1])ans++;

    if(w[y]>1&&loc[w[y]-1]>=x&&loc[w[y]-1]<loc[w[y]])ans++;
    if(w[y]<n&&loc[w[y]+1]>=x&&loc[w[y]]>loc[w[y]+1])ans--;

    if(w[x]-w[y]==1)ans++;
    if(w[y]-w[x]==1)ans--;
}

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>w[i],loc[w[i]]=i;

    FOR(i,2,n){
        ans+=(loc[i]<loc[i-1]);
    }

    while(m--){
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);

        work(a,b);

        swap(loc[w[a]],loc[w[b]]);
        swap(w[a],w[b]);
        cout<<ans<<endl;
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}