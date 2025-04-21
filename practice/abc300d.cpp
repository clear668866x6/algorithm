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

int n;
int primes[N],cnt;
bool vis[N];

void init(int x){
    for(int i=2;i<=x;i++){
        if(!vis[i])primes[cnt++]=i;
        for(int j=0;i*primes[j]<=x;j++){
            vis[i*primes[j]]=1;
            if(i%primes[j]==0)break;
        }
    }
}

void solve() {
    cin>>n;

    init(N-10);

    int ans=0;

    FOR(a,0,cnt-1){
        if(primes[a]*primes[a]*primes[a]*primes[a]*primes[a]>n)break;
        FOR(b,a+1,cnt-1){
            if(primes[a]*primes[a]*primes[b]*primes[b]*primes[b]>n)break;
            FOR(c,b+1,cnt-1){
                int t=primes[a]*primes[a]*primes[b]*primes[c]*primes[c];
                if(t>n)break;
                ans++;
            }
        }
    }

    cout<<ans;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}