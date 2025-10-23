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

string a,b;

void solve() {
    cin>>a>>b;

    int n=a.sz,m=b.sz;

    n=max(n,m);

    map<char,int>mp1,mp2;
    VI i1(n+n,0),i2(n+n,0);
    
    FORD(i,0,b.sz-1){
        i1[i]=++mp1[b[i]];
    }

    FORD(i,0,a.sz-1){
        if(mp1[a[i]]){
            i2[i]=++mp2[a[i]];
        }
    }

    int cnt=0;

    FOR(i,0,a.sz-1){
        if(a[i]==b[cnt]&&i2[i]==i1[cnt]){
            cnt++;
        }
    }

    if(cnt==b.sz){
        YES;
    }else{
        NO;
    }

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}