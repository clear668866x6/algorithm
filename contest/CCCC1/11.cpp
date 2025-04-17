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
struct E{
    int l,date,r;
}tr[N];

void dfs(int u){
    if(u>n)RE;
    if(tr[u].l)dfs(tr[u].l);
    if(tr[u].r)dfs(tr[u].r);
    cin>>tr[u].date;
}

void solve() {
    cin>>n;

    FOR(i,1,n){
        if(i*2<=n)tr[i].l=i*2;
        if(i*2+1<=n)tr[i].r=i*2+1;
    }

    dfs(1);

    queue<int>q;

    q.push(1);

    VI ans;

    while(q.sz){
        int t=q.front();
        q.pop();

        ans.pb(tr[t].date);

        if(tr[t].l)q.push(tr[t].l);
        if(tr[t].r)q.push(tr[t].r);
    }

    FOR(i,0,ans.sz-1){
        cout<<ans[i]<<" \n"[i==ans.sz-1];
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}