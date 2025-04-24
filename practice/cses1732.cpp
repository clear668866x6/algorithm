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
constexpr int N = 2e6 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

namespace KMP{
    string a,b;//a为要匹配的（短的），b为匹配的（长的）
    int ne[N];
    int n,m;

    void get_ne(){
        int j=0;
        n=a.sz;
        a=' '+a;
        
        FOR(i,2,n){
            while(j&&a[i]!=a[j+1])j=ne[j];
            if(a[i]==a[j+1])j++;
            ne[i]=j;
        }
    }

    void work(){
        m=b.sz;

        b=' '+b;

        get_ne();

        int j=0;
        FOR(i,1,m){
            while(j&&b[i]!=a[j+1])j=ne[j];
            if(a[j+1]==b[i])j++;
            if(j==n){
                //操作
                j=ne[j];
            }
        }
    }
}

using namespace KMP;

void solve() {
    cin>>a;

    get_ne();

    VI ans;

    int t=ne[n];

    while(t)ans.pb(t),t=ne[t];

    sort(ALL(ans));

    for(auto x:ans)cout<<x<<' ';
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}