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

int k,l1,r1,l2,r2;

void solve() {
    cin>>k>>l1>>r1>>l2>>r2;

    int ans=0,t=1;

    FOR(i,0,30){
        int l=l1-1,r=r1+1;
        while(l+1!=r){
            int mid=l+r>>1;
            if(t*mid>=l2)r=mid;
            else l=mid;
        }
        
        int ansl=r;
        
        l=l1-1,r=r1+1;
        
        while(l+1!=r){
            int mid=l+r>>1;
            if(t*mid<=r2)l=mid;
            else r=mid;
        }
        
        int ansr=l;
        
        if(ansl<=ansr){
            ans+=(ansr-ansl+1);
        }
        t*=k;
        if(t>r2)break;
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