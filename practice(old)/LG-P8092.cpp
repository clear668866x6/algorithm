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

    VI a(n+1);

    FOR(i,1,n)cin>>a[i];

    if(n>1&&(a[1]>a[2]||a[n-1]<a[n])){
        cout<<-1<<endl;
        RE;
    }

    if(n<3){
        cout<<0<<endl;
        RE;
    }

    int l=-1,r=1e12;

    function<bool(int)> check=[&](int x){
        auto b=a;

        FOR(i,1,n-1){
            if(b[i]<x)return false;
            b[i+1]-=(b[i]-x);
        }
        return b[n]>=x;
    };

    while(l+1!=r){
        int mid=l+r>>1;
        if(check(mid))l=mid;
        else r=mid;
    }

    int t=*max_element(ALL(a));

    if(l>t||l<0){
        cout<<-1<<endl;
        RE;
    }

    int ans=0;

    FOR(i,1,n){
        ans+=abs(a[i]-l);
    }

    cout<<ans<<endl;

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}