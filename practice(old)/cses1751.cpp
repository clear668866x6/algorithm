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

int n;
/// @brief 跳2^20步肯定到环上
int vis[N];
int f[N][30];
int ans[N];

int calc(int x){
    if(ans[x]){
        return ans[x];
    }
    return ans[x]=calc(f[x][0])+1;
}

void solve() {
    cin>>n;

    FOR(i,1,n){
        cin>>f[i][0];
    }

    FOR(j,1,20){
        FOR(i,1,n){
            f[i][j]=f[f[i][j-1]][j-1];
        }
    }

    FOR(i,1,n){
        int x=f[i][19],y=f[x][0];
        if(ans[x])continue;
        ans[x]=1;
        while(y!=x)y=f[y][0],ans[x]++;
        y=f[y][0];
        while(y!=x)ans[y]=ans[x],y=f[y][0];
    }

    FOR(i,1,n){
        if(!ans[i]){
            ans[i]=calc(i);
        }
    }

    FOR(i,1,n){
        cout<<ans[i]<<' ';
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}