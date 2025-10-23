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

    FOR(i,1,n)cin>>w[i];

    array<set<int>,3>s;

    int t0=0,t1=0,t2=0;

    FOR(i,1,n){
        if(w[i]==0)t0++;
        else if(w[i]==1)t1++;
        else t2++;
        s[w[i]].insert(i);
    }

    // s[2].insert(n);

    VPII ans;

    FOR(i,t1+t0+1,n){
        if(w[i]==0){
            //0->1 
            int t=*s[1].begin();
            ans.pb({i,t});
            s[0].erase(s[0].find(i));
            s[0].insert(t);
            s[1].erase(s[1].find(t));
            s[1].insert(i);
            swap(w[i],w[t]);
        }
        if(w[i]==1){
            int t=*s[2].begin();
            ans.pb({i,t});
            s[1].erase(s[1].find(i));
            s[1].insert(t);
            s[2].erase(s[2].find(t));
            s[2].insert(i);
            swap(w[i],w[t]);
        }
        //1->2
    }


    FOR(i,t0+1,t0+t1){
        if(w[i]==0){
            int t=*s[1].begin();
            ans.pb({i,t});
            s[0].erase(s[0].find(i));
            s[0].insert(t);
            s[1].erase(s[1].find(t));
            s[1].insert(i);
            swap(w[i],w[t]);
        }
    }

    // FOR(i,1,n){
    //     cout<<w[i]<<" \n"[i==n];
    // }

    cout<<ans.sz<<endl;

    for(auto [x,y]:ans){
        cout<<x<<' '<<y<<endl;
    }

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}