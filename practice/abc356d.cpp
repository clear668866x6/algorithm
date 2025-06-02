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
//卡在：已经想到贡献法了，也想到了对于1的两端乘起来，但漏考虑了n的这一位是1的情况下，还要加上剩下的部分(这部分就越是当最高位是1的情况下的情况)。
void solve() {
    int n,m;
    cin>>n>>m;
    n++;
    int ans=0,mod=998244353;

    FOR(i,0,63){
        if(m>>i&1){
            int t=1LL<<i;
            int l=(n/t/2)*t,r=((n>>i&1)*(n&(t-1)));//r就是剩下的
            (ans+=l+r)%=mod;
        }
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