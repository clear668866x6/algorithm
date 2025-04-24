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
constexpr int mod = 1e9 + 7;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int a,b;
int fac[N],infac[N];

int qmi(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

void init(int x){
    fac[0]=infac[0]=1;
    FOR(i,1,x){
        fac[i]=fac[i-1]*i%mod;
    }
    infac[x]=qmi(fac[x],mod-2);
    FORD(i,1,x-1){
        infac[i]=infac[i+1]*(i+1)%mod;
    }
}

int C(int x,int y){
    if(x<y||x<0||y<0)return 0;
    return fac[x]*infac[y]%mod*infac[x-y]%mod;
}

void solve() {
    
    string s;

    cin>>s;
 
    map<char,int>mp;

    for(auto x:s)mp[x]++;

    int ans=1,tot=s.sz;

    for(auto [x,y]:mp){
        (ans*=C(tot,y))%=mod;
        tot-=y;
    }

    cout<<ans<<endl;
}

signed main() {
    int Task = 1;

    init(N-10);
    
    for (; Task; Task--) {
        solve();
    }
    return 0;
}