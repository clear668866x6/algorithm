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

int n,s;
int a[N],b[N];
VI g[N];
bool vis[N];

void solve() {
    cin>>n>>s;

    VI p1;

    FOR(i,1,n)cin>>a[i];
    FOR(i,1,n)cin>>b[i];

    FOR(i,1,n){
        if(a[i]){
            p1.pb(i);
        }
    }

    FOR(i,1,p1.sz-1){
        g[p1[i-1]].emplace_back(p1[i]);
    }

    p1.clear();

    FORD(i,1,n){
        if(b[i]){
            p1.pb(i);
        }
    }

    FOR(i,1,p1.sz-1){
        g[p1[i-1]].emplace_back(p1[i]);
    }

    queue<int>q;

    q.push(1);
    vis[1]=1;
    while(q.sz){
        int t=q.front();
        q.pop();

        if(t==s){
            Yes;
            RE;
        }

        for(auto& j:g[t]){
            if(vis[j])continue;
            vis[j]=1;
            q.push(j);
        }
    }

    No;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}