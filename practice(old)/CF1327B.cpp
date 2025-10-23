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

int n;

void solve() {
    cin>>n;

    VI vis1(n+1,0),vis2(n+1,0);

    FOR(i,1,n){
        int k,x;
        cin>>k;
        bool f=false;
        while(k--){
            cin>>x;
            if(!f&&!vis2[x]){
                f=1;
                vis2[x]=1;
                vis1[i]=1;
            }
        }
    }

    bool f=false;
    VI v1,v2;

    FOR(i,1,n){
        if(!vis1[i]||!vis2[i]){
            f=1;
            if(!vis1[i]){
                v1.pb(i);
            }
            if(!vis2[i]){
                v2.pb(i);
            }
        }
    }

    if(!f){
        cout<<"OPTIMAL"<<endl;
    }else{
        cout<<"IMPROVE"<<endl;
        FOR(i,0,0){
            cout<<v1[i]<<' '<<v2[i]<<endl;
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