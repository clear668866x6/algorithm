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
constexpr int N = 5e3 + 10;
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

    FOR(i,1,n)cin>>w[i];

    map<int,int>mp;

    FOR(i,1,n)mp[w[i]]++;

    if(mp[w[1]]==n){
        NO;
        RE;
    }

    YES;

    map<int,VI>mp2;
    VI vis(n+1,0),b(n);

    FOR(i,1,n){
        mp2[w[i]].emplace_back(i);
        b.pb(w[i]);
    }

    sort(ALL(b));
    b.erase(unique(ALL(b)),b.end());

    int lst=-1;
    bool f=false;

    for(auto [x,y]:mp2){
        if(!f){
            f=1;
            lst=x;
            continue;
        }    
        vis[y[0]]=1;
        for(auto t:mp2[lst]){
            cout<<y[0]<<" "<<t<<endl;
            vis[t]=1;
        }
        lst=x;
    }

    FOR(i,1,n){
        if(!vis[i]){
            cout<<mp2[b[b.sz-2]][0]<<' '<<i<<endl;
        }
    }

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}