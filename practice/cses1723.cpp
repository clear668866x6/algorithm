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
constexpr int N = 110;
constexpr int mod = 1e9 + 7;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

namespace Matrix{
    struct E{
        int n,m;
        int x[N][N];
    }A,B;

    E operator*(const E& a,const E& b){
        E res;
        res.n=a.n,res.m=b.m;
        memset(res.x,0,sizeof res.x);
        FOR(i,0,res.n-1){
            FOR(j,0,res.m-1){
                FOR(k,0,a.m-1){
                    res.x[i][j]=(res.x[i][j]+a.x[i][k]*b.x[k][j]%mod)%mod;
                }
            }
        }
        return res;
    }

    E qmi(E a,int b){
        E p=a;
        while(b){
            if(b&1)B=B*p;
            p=p*p;
            b>>=1;
        }
        return B;
    }
}

using namespace Matrix;

int n,m,k;

void solve() {
    cin>>n>>m>>k;

    A.n=A.m=n;
    B.n=B.m=n;

    FOR(i,0,n-1)B.x[i][i]=1;

    FOR(i,1,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        A.x[a][b]++;
    }

    cout<<(qmi(A,k).x[0][n-1]);
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}