#include <bits/stdc++.h>
using namespace std;

// #define int int64_t
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
constexpr int N = 6e6 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int l,r;
bitset<100000010>vis;
int primes[N],cnt;
int ct[N];

int read(){
    int s=0,f=0;
    char ch=getchar_unlocked();
    while(!isdigit(ch))f|=(ch=='-'),ch=getchar_unlocked();
    while(isdigit(ch))s=(s<<3)+(s<<1)+ch-'0',ch=getchar_unlocked();
    return f?-s:s;
}

bool check(int x){
    // string p=to_string(x);
    int res=0;
    // for(auto x:p){
    //     res+=(x-'0');
    // }

    while(x){
        res+=(x%10);
        x/=10;
    }

    return !vis[res];
}

void init(int x){
    for(register int i=2;i<=x;i++){
        if(!vis[i])primes[++cnt]=i;
        for(register int j=1;primes[j]<=x/i&&j<=cnt;j++){
            vis[i*primes[j]]=1;
            if(i%primes[j]==0)break;
        }
    }

    int t=0;

    for(register int i=1;i<=cnt;i++){//少开数组
        if(check(primes[i])){
            primes[++t]=primes[i];
        }
    }
    cnt=t;
}

void solve() {
    cin>>l>>r;

    int R=upper_bound(primes+1,primes+1+cnt,r)-primes;
    int L=lower_bound(primes+1,primes+1+cnt,l)-primes;
    cout<<R-L<<endl;
}

signed main() {
    int Task = 1;

    init(1e8+2);

    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}