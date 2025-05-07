#include <bits/stdc++.h>
using namespace std;

#define int int64_t
// #define endl "\n"
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
VPII ans;
bool vis[N];

int query(int x,int y){
    cout<<"? "<<x<<' '<<y<<endl;
    int res;
    cin>>res;
    return res;
}

void dfs(int l,int r){
    vis[r]=1;
    int t=query(l,r);
    if(t==l){
        ans.pb({l,r});
        RE;
    }

    if(!vis[t])dfs(l,t);
    dfs(t,r);
}

void solve() {
    cin>>n;

    FOR(i,2,n){
        if(!vis[i]){
            dfs(1,i);
        }
    }
    
    cout<<"! ";
    for(auto [x,y]:ans){
        cout<<x<<' '<<y<<' ';
    }
    cout<<endl;
    FOR(i,1,n)vis[i]=0;
    ans.clear();

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}