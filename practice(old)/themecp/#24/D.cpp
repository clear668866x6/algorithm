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

void solve() {
    cin>>n;

    VI t0,t1,t2;

    array<set<int>,3>s;

    FOR(i,1,n)cin>>w[i];

    FOR(i,1,n){
        s[w[i]].insert(i);
    }

    s[2].insert(n);
    s[0].insert(-1);

    VPII ans;
    
    while(1){
        int u=*s[0].rbegin();
        int v=*s[1].begin();

        if(u>v){
            ans.pb({u,v});
            s[1].erase(s[1].find(v));
            s[0].erase(s[0].find(u));
            s[1].insert(u);
            s[0].insert(v);
        }else{
            u=*s[1].rbegin();
            v=*s[2].begin();
            if(u>v){
                ans.pb({u,v});
                s[1].erase(s[1].find(u));
                s[2].erase(s[2].find(v));
                s[1].insert(v);
                s[2].insert(u);
            }else{
                break;
            }
        }
    }

    cout<<ans.sz<<endl;

    for(auto [x,y]:ans){
        cout<<x<<" "<<y<<endl;
    }

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}