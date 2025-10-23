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

//总的-是倍数关系的（容斥原理，采用莫比乌斯函数能做到线性的时间复杂度）

int primes[N],t[N],mu[N],cnt;
bool vis[N];
int n,num[N];

void init(int x){
    mu[1]=1;
    for(int i=2;i<=x;i++){
        if(!vis[i])primes[cnt++]=i,mu[i]=-1;
        for(int j=0;i*primes[j]<=x;j++){
            vis[i*primes[j]]=1;
            if(i%primes[j]==0){
                mu[i*primes[j]]=0;
                break;
            }
            mu[i*primes[j]]=-mu[i];
        }
    }
}

void solve() {
    init(N-10);

    cin>>n;

    FOR(i,1,n){
        int x;
        cin>>x;
        num[x]++;
    }

    FOR(i,1,1e6){
        FOR2(j,i,1e6,i){
            t[i]+=num[j];
        }
    }

    int ans=0;

    FOR(i,1,1e6)ans+=mu[i]*(t[i]-1)*t[i]/2;

    cout<<ans;
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}