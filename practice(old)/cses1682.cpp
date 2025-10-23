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
VI g1[N],g2[N];
bool vis1[N],vis2[N];

void dfs1(int u){
    if(vis1[u])RE;
    vis1[u]=1;

    for(auto& j:g1[u]){
        dfs1(j);
    }
}

void dfs2(int u){
    if(vis2[u])RE;
    vis2[u]=1;

    for(auto& j:g2[u]){
        dfs2(j);
    }
}

void solve() {
    cin>>n>>m;

    FOR(i,1,m){
        int a,b;
        cin>>a>>b;
        g1[a].emplace_back(b);
        g2[b].emplace_back(a);
    }

    dfs1(1);
    FOR(i,1,n){
        if(!vis1[i]){
            NO;
            cout<<"1 "<<i<<endl;
            RE;
        }
    }

    dfs2(1);
    FOR(i,1,n){
        if(!vis2[i]){
            NO;
            cout<<i<<" 1"<<endl;
            RE;
        }
    }

    YES;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}