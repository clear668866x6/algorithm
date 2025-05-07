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
constexpr int N = 1e5 + 10,M = 4e4;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,w[N];
int primes[N],cnt;
bool vis[N];
unordered_map<int,int>mp;

void init(int x){
    FOR(i,2,x){
        if(!vis[i])primes[cnt++]=i;
        for(int j=0;i*primes[j]<=x;j++){
            vis[primes[j]*i]=1;
            if(i%primes[j]==0)break;
        }
    }
}

void solve() {
    cin>>n;
    mp.clear();

    FOR(i,1,n)cin>>w[i];

    FOR(i,1,n){
        int x=w[i];
        if(x==1)continue;
        for(int j=0;j<cnt&&primes[j]*primes[j]<=x;j++){
            int p=primes[j];
            if(x%p==0){
                mp[p]++;
                while(x%p==0)x/=p;  
            }
        }
        if(x>1){
            if(mp[x]){
                YES;
                RE;
            }
            mp[x]++;
        }
    }

    for(auto [x,y]:mp){
        if(y>1){
            YES;
            RE;
        }
    }

    NO;

}

signed main() {
    int Task = 1;
    init(M);
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}