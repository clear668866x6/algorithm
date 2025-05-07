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

int n,d;

void solve() {
    cin>>n>>d;

    if(n==1){
        FOR2(i,1,10,2){
            if(d%i==0){
                cout<<i<<' ';
            }
        }
        cout<<endl;
        RE;
    }

    FOR2(i,1,10,2){
        if(i==1){
            cout<<1<<' ';
        }else if(i==3){
            if(d%i==0||(n>=3)){
                cout<<i<<' ';
            }
        }else if(i==5){
            if(d==5){
                cout<<i<<' ';
            }
        }else if(i==7){
            if(n>=3||d==7){
                cout<<i<<' ';
            }
        }else{
            if(d==9||(n>=3&&d%3==0)||n>=6){
                cout<<i<<' ';
            }
        }
    }
    cout<<endl;

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}