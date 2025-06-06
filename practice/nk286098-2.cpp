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

void solve() {
    int n, m;
    cin >> n >> m;
    V<int>w(n);
    for (auto& x : w)cin >> x;
    V<int>a(n), b(n);
    FOR(i, 0, n - 1)cin >> a[i] >> b[i];

    map<int, V<PII>>mp;
    V<int>s(n + 1, 0);

    FOR(i, 0, n - 1){
        s[w[i] + m - 1] += b[i];
        mp[w[i] + m - 1].eb(a[i], b[i]);
    }

    FOR(i, 1, n)s[i] += s[i - 1];

    V<int>f(n + 1, 1e18);
    f[0] = 0;

    FOR(i, 1, n){
        for (auto [a, b] : mp[i]){
            int t = max<int>(1, i - m + 1);
            f[i] = min(f[i], f[t - 1] + s[i] - s[t - 1] - b + a);//这个地方要注意：因为它很可能有重合的实际时间
        }
        f[i] = min(f[i], f[i - 1] + s[i] - s[i - 1]);
    }
    cout << f[n];
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