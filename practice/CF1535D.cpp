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

int tr[N];
int k,q;
string s,d;
int n;

void build(int u,int l,int r){
    if(l==r){
        tr[u]=1;
        RE;
    }

    int mid=l+r>>1;

    build(u<<1,l,mid),build(u<<1|1,mid+1,r);

    if(d[u]=='1')tr[u]=tr[u<<1];
    if(d[u]=='0')tr[u]=tr[u<<1|1];
    if(d[u]=='?')tr[u]=tr[u<<1]+tr[u<<1|1];
}

void solve() {
    cin>>k>>s;
    s=' '+s;
    n=(1ll<<k);
    d.resize(n);

    FOR(i,1,n-1){
        d[i]=s[n-i];
    }

    build(1,1,n);

    cin>>q;

    while(q--){
        int p;
        char c;
        cin>>p>>c;
        p=n-p;
        d[p]=c;
        while(p){
            if(d[p]=='1')tr[p]=tr[p<<1];
            if(d[p]=='0')tr[p]=tr[p<<1|1];
            if(d[p]=='?')tr[p]=tr[p<<1]+tr[p<<1|1];
            p>>=1;
        }
        cout<<tr[1]<<endl;
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}