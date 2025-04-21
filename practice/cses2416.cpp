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

int n,m,w[N],q;
int f[N][24];
int g[N][24];
int s[N];
int stk[N],top;
//倍增求让数组非严格单调递增的题目

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>w[i],s[i]=s[i-1]+w[i];

    stk[++top]=n+1;
    w[n+1]=1e18;

    FORD(i,1,n){
        while(top&&w[i]>=w[stk[top]])top--;
        f[i][0]=stk[top];
        g[i][0]=(f[i][0]-i)*w[i];
        stk[++top]=i;
    }

    FOR(j,1,23){
        FORD(i,1,n){
            f[i][j]=f[f[i][j-1]][j-1];
            g[i][j]=g[i][j-1]+g[f[i][j-1]][j-1];
        }
    }

    while(m--){
        int l,r;
        cin>>l>>r;
        int ans=-(s[r]-s[l-1]);
        int k=l;
        FORD(j,0,23){
            if(f[k][j]&&f[k][j]<=r+1){
                ans+=g[k][j];
                k=f[k][j];
            }
        }
        ans+=(r-k+1)*w[k];
        cout<<ans<<endl;
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}