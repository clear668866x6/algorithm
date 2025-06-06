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
    int n, k;
    cin >> n >> k;
    struct E{
        int w, a, b;
        bool operator<(const E& t)const{
            return w < t.w;
        }
    };
    V<E>w(n + 1);
    V<int>pre(n + 2, 0);
    FOR(i, 0, n - 1)cin >> w[i].w;
    FOR(i, 0, n - 1)cin >> w[i].a >> w[i].b;
    w[n].w = 1e18;
    sort(ALL(w));
    FOR(i, 1, n){
        pre[i] = pre[i - 1] + w[i - 1].b;
    }
    V<int>f(n + 1, 1e18);
    f[0] = 0;
    FOR(i, 1, n){
        if (i - k + 1 >= 0){
            int r = lower_bound(ALL(w), E{ i,-1,-1 }) - w.begin();
            int l = upper_bound(ALL(w), E{ w[r].w - k + 1,-1,-1 }) - w.begin() - 1;
            cout << l << ' ' << r << ' ' << i << endl;
            if (r == 0){
                f[i] = min(f[i], f[i - k + 1] + w[r].a);
            } else{
                f[i] = min(f[i], f[i - k + 1] + pre[r - 1] - pre[l] + w[r].a);
            }
        } else{
            int r = lower_bound(ALL(w), E{ i,-1,-1 }) - w.begin();
            f[i] = min(f[i], f[i - 1] + pre[r] - pre[r - 1]);
        }
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