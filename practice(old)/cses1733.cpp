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

namespace exKMP{
    int z[N];//以i开头的后缀和整个字符串前缀匹配的最长长度。
    string s;
    int n;

    void work(){
        int l,r=0;
        z[1]=n;

        FOR(i,2,n){
            if(i<=r)z[i]=min(z[i-l+1],r-i+1);
            while(s[1+z[i]]==s[i+z[i]])z[i]++;
            if(i+z[i]-1>r)l=i,r=i+z[i]-1;
        }
    }
}

using namespace exKMP;

void solve() {
    cin>>s;

    n=s.sz;

    s=' '+s;

    work();

    FOR(i,2,n){
        if(z[i]>n-i){
            cout<<i-1<<' ';
        }
    }
    cout<<n;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}