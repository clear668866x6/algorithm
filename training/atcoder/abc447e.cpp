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

constexpr int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;

    V<array<int, 3>> w(m + 1);

    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        w[i] = {a, b, i};
    }

    auto qmi = [&](int a, int b) {
        int ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    };

    V<int> p(n + 1, 0);
    iota(ALL(p), 0ll);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    int ans = 0;

    int l = -1, r = m + 1;

    auto check = [&](int x) {
        iota(ALL(p), 0ll);
        int cnt = 0;
        FOR(i, x, m) {
            auto [a, b, idx] = w[i];
            a = find(a), b = find(b);
            if (a != b) {
                p[a] = b;
            }
        }
        FOR(i, 1, n) {
            if (i == p[i]) cnt++;
        }

        if (cnt >= 2) return 1;
        return 0;
    };

    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    check(r);

    FOR(i, 1, m) {
        auto [a, b, idx] = w[i];
        a = find(a), b = find(b);
        if (a != b) {
            ans += qmi(2, i);
            ans %= mod;
        }
    }

    cout << ans;
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