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

int n,x;

void solve() {
    cin>>n>>x;

    if(n<x){
        cout<<-1<<endl;
        RE;
    }

    string a,b;

    int na=n,nb=x;

    while(n){
        a+=(n%2);
        n>>=1;
    }

    while(x){
        b+=(x%2);
        x>>=1;
    }

    while(a.sz<b.sz){
        a.pb(0);
    }

    while(a.sz>b.sz){
        b.pb(0);
    }

    reverse(ALL(a)),reverse(ALL(b));

    FOR(i,0,a.sz-1){
        if(a[i]!=b[i]&&b[i]=='1'){
            cout<<-1<<endl;
            RE;
        }
    }

    n=na;

    while(na!=nb){
        n+=lowbit(n);
        na&=n;
        if(na<nb){
            cout<<-1<<endl;
            RE;
        }
    }
    cout<<n<<endl;
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}