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

int l,r,m;

bool check(int a,int x){
    int t=a*x;
    return t-m>=0;
}

void solve() {
    cin>>l>>r>>m;

    FOR(a,l,r){
        int L=0,R=1e12+1;
        while(L+1!=R){
            int mid=L+R>>1;
            if(check(a,mid))R=mid;
            else L=mid;
        }
        int t=R*a;
        int t2=L*a;
        // if(a==800){
            // cout<<(m+m-t2)<<' '<<endl;
        // }
        if(m-t2<=r-l&&t2>0){
            if(t2%a!=0)continue;
            cout<<a<<' '<<l+m-t2<<' '<<l<<endl;
            RE;
        }
        if(t-m<=r-l){
            cout<<a<<' '<<l<<' '<<l+t-m<<endl;
            RE;
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