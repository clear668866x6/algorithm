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
constexpr int N = 6;
constexpr int mod = 1e9 + 7;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n;
int f[6]={32,16,8,4,2,1};
int A[6][6]={
    {1,1,1,1,1,1},
    {1,0,0,0,0,0},
    {0,1,0,0,0,0},
    {0,0,1,0,0,0},
    {0,0,0,1,0,0},
    {0,0,0,0,1,0}
};
int res[N][N];

void mul(int c[],int a[],int b[][6]){
    int temp[N]={0};
    FOR(i,0,N-1){
        FOR(j,0,N-1){
            temp[i]=(temp[i]+a[j]*b[j][i])%mod;
        }
    }
    memcpy(c,temp,sizeof temp);
}

void mul(int c[][N],int a[][N],int b[][N]){
    int temp[N][N]={0};
    FOR(i,0,N-1){
        FOR(j,0,N-1){
            FOR(k,0,N-1){
                temp[i][j]=(temp[i][j]+a[i][k]*b[k][j]%mod)%mod;
            }
        }
    }
    memcpy(c,temp,sizeof temp);
}

void solve() {
    cin>>n;

    if(n<=6){
        cout<<f[6-n]<<endl;
        RE;
    }

    n-=6;

    FOR(i,0,5)res[i][i]=1;

    while(n){
        if(n&1)mul(res,res,A);
        mul(A,A,A);
        n>>=1;
    }

    int ans=0;

    FOR(i,0,5){
        ans=(ans+f[i]*res[0][i]%mod)%mod;
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