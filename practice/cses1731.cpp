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
constexpr int N = 1e6 + 10;
constexpr int mod = 1e9 + 7;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

string s;
int tr[N][30],cnt[N];
int n,m,idx;
int f[N];

void solve() {
    cin>>s>>m;
    n=s.sz;

    s=' '+s;

    while(m--){
        string a;
        cin>>a;
        int p=0;
        for(auto x:a){
            x-='a';
            if(!tr[p][x])tr[p][x]=++idx;
            p=tr[p][x];
        }
        cnt[p]++;
    }

    f[0]=1;

    FOR(i,0,n-1){
        int p=0;
        FOR(j,i+1,n){
            if(!tr[p][s[j]-'a']){
                break;
            }
            p=tr[p][s[j]-'a'];
            f[j]=(f[j]+f[i]*cnt[p])%mod;
        }
    }
    cout<<f[n];

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}