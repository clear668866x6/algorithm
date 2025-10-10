#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) (int)(x).size()

struct ST {
    static constexpr int N = 2e5 + 10;
    int f[N][22];

    void init(V<int> w, int n) {
        FOR(j, 0, 20) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                if (!j)
                    f[i][j] = w[i];
                else
                    f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int len = log2(r - l + 1);
        return max(f[l][len], f[r - (1 << len) + 1][len]);
    }

} A;

void solve() {
    int n, s, x;
    cin >> n >> s >> x;
    V<int> a(n + 1, 0);
    map<int, V<int>> mp;
    FOR(i, 1, n) cin >> a[i];
    V<int> pre(n + 1, 0);
    A.init(a, n);
    FOR(i, 1, n) pre[i] = pre[i - 1] + a[i];
    FOR(i, 1, n) {
        mp[pre[i]].eb(i);
    }

    int ans = 0;

    FOR(i, 1, n) {
        int t = s + pre[i - 1];

        auto it = lower_bound(ALL(mp[t]), i);
        if (it == mp[t].end()) continue;

        int p = it - mp[t].begin();

        int ansl = 0, ansr = sz(mp[t]) - 1;

        if (ansl > ansr) {
            continue;
        }

        int l = p - 1, r = sz(mp[t]);
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (A.query(i, mp[t][mid]) >= x)
                r = mid;
            else
                l = mid;
        }

        ansl = r;

        l = p - 1, r = sz(mp[t]);
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (A.query(i, mp[t][mid]) <= x)
                l = mid;
            else
                r = mid;
        }
        ansr = l;

        ans += ansr - ansl + 1;
    }

    cout << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}
