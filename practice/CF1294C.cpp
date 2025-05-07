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

    int cnt=0,t=n;

    VPII p;

    for(int i=2;i<=n/i;i++){
        if(n%i==0){
            int c=0;
            while(n%i==0){
                n/=i;
                c++;
            }
            cnt++;
            p.pb({i,c});
        }
    }
    if(n>1)cnt++,p.pb({n,1});

    sort(ALL(p));
    
    if(p.sz==1){
        if(p[0].se>=6){
            YES;
            cout<<p[0].fi<<' '<<p[0].fi*p[0].fi<<' '<<t/p[0].fi/p[0].fi/p[0].fi<<endl;
        }else{
            NO;
        }
    }else{
        int x=p[0].fi,y=p[1].fi,z=t/x/y;
        if(z==x||z==y||z==1){
            NO;
        }else{
            YES;
            cout<<x<<' '<<y<<' '<<z<<endl;
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