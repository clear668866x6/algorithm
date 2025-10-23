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
constexpr int N = 2e3 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n;
int w[N];

void solve() {
    cin>>n;

    FOR(i,1,n*2)cin>>w[i];
    sort(w+1,w+1+n*2);
    bool f=false;

    FOR(i,1,n*2-1){
        multiset<int>mp;
        FOR(i,1,n*2)mp.insert(w[i]);    
        VPII ans;
        ans.pb({w[i],w[2*n]});
        mp.erase(mp.find(w[i]));
        mp.erase(mp.find(w[2*n]));
        int idx=2*n-1,lst=w[2*n];
        FORD(j,1,idx){
            if(!mp.count(w[j]))continue;
            if(mp.count(lst-w[j])){
                mp.erase(mp.find(lst-w[j]));
                if(mp.find(w[j])==mp.end())break;
                mp.erase(mp.find(w[j]));
                ans.pb({lst-w[j],w[j]});
            }
            lst=w[j];
        }
        if(!mp.sz){
            f=1;
            YES;
            cout<<ans[0].fi+ans[0].se<<endl;
            for(auto [x,y]:ans){
                cout<<x<<' '<<y<<endl;
            }
            RE;
        }
    }
    if(!f){
        NO;
    }
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}