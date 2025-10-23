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

int f[70][70][40];
int g[70][70];
int x,y;

void init(){
    FOR(i,0,60){
        FOR(j,0,60){
            FOR(k,0,30){
                f[i][j][k]=1e18;
            }
            g[i][j]=1e18;
        }
    }

    FOR(i,0,30)f[0][0][i]=0;

    FOR(i,0,60){
        FOR(j,0,60){
            FOR(k,0,30){
                if(i+j!=0&&k){
                    f[i][j][k]=min<int>(f[i][j][k],f[i][j][k-1]);
                    if(j-k>=0)f[i][j][k]=min<int>(f[i][j][k],f[i][j-k][k-1]+(1ll<<k));
                    if(i-k>=0)f[i][j][k]=min<int>(f[i][j][k],f[i-k][j][k-1]+(1ll<<k));
                }
            }
        }
    }

    FOR(i,0,60){
        FOR(j,0,60){
            FOR(k,0,30){
                g[i][j]=min(g[i][j],f[i][j][k]);
            }
        }
    }

}

void solve() {
    cin>>x>>y;

    if(x==y){
        cout<<0<<endl;
        RE;
    }

    VI a,b;

    while(x){
        a.pb(x&1);
        x/=2;
    }

    while(y){
        b.pb(y&1);
        y/=2;
    }

    int idx=0;

    int l1=a.sz,l2=b.sz;

    for(int i=l1-1,j=l2-1;i>=0&&j>=0;i--,j--){
        if(a[i]==b[j]){
            idx++;
        }else{
            break;
        }
    }

    int t1=l1-idx,t2=l2-idx;

    int ans=1e18;

    FOR(i,0,idx){
        ans=min(ans,g[t1+i][t2+i]);
    }

    FOR(i,l1,60){
        FOR(j,l2,60){
            ans=min(ans,g[i][j]);
        }
    }
    cout<<ans<<endl;

}

signed main() {
    int Task = 1;
    init();
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}