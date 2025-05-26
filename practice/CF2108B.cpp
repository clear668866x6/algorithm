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

    if(n==1&&!x){
        cout<<-1<<endl;
        RE;
    }

    if(n==2&&x==1){
        cout<<5<<endl;
        RE;
    }

    if(!x){
        if(n&1){
            cout<<(n-2+3+2)<<endl;
        }else{
            cout<<n<<endl;
        }
        RE;
    }

    if(x==1){
        if(n&1){
            cout<<n<<endl;
        }else{
            cout<<n-2+3+2<<endl;
        }
        RE;
    }

    int cnt=0;

    FORD(i,0,30){
        if(x>>i&1){
            cnt++;
        }
    }

    if(n<=cnt){
        cout<<x<<endl;
        RE;
    }

    int res=0;

    if((n-cnt)&1){
        res=x+1;
        res+=(n-cnt);
    }else{
        res=x+1;
        res+=(n-cnt-1);
    }
    cout<<res<<endl;

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}