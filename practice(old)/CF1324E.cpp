#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()
//dp 的题目可以让无效的状态设为-1,dp的值最好和题目要求的东西一致
void solve() {
    int n,h,l,r;
    cin>>n>>h>>l>>r;

    V<int> w(n+1,0);
    FOR(i,1,n)cin>>w[i];

    V<V<int>>f(n+1,V<int>(h,-1e18));

    f[0][0]=0;
    
    FOR(i,1,n){
        FOR(j,0,h-1){
            f[i][j]=max(f[i-1][((j-w[i]+1)%h+h)%h]+(j>=l&&j<=r),f[i-1][((j-w[i])%h+h)%h]+(j>=l&&j<=r));
        }
    }

    int ans=0;

    FOR(i,0,h-1){
        ans=max(ans,f[n][i]);
    }

    cout<<ans;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}