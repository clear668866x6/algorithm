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

void solve() {
    int n, m;
    cin >> n >> m;
    V<int> w(n + 1, 0);
    V<int> b(n + 1, 0);
    FOR(i, 1, n) cin >> w[i], b[i] = i - 1;

    if (!m) {
        int tot = 0;
        FOR(i, 1, n) tot += (w[i] == 0);
        if (!tot) {
            cout << n + 1 << endl;
            RE;
        }
        V<int> c;
        FOR(i, 1, n) {
            if (w[i]) {
                b[i]++;
            }
            c.eb(b[i]);
        }

        int t = 1;
        sort(ALL(c));
        c.erase(unique(ALL(c)));
        FORD(i, 0, sz(c) - 1) {
            if (c[i] == tot) {
                break;
            }
            t++;
        }
        cout << t << endl;

        RE;
    }

    auto check = [&](int x) {
        int tot = w[n - x + 1];
        int del = n - x - 1;
        priority_queue<int, V<int>, greater<int>> q;
        FOR(i, 1, n) {
            if (i == n - x + 1) continue;
            q.push(w[i]);
        }

        while (del--) {
            tot += q.top();
            q.pop();
        }

        return tot <= m;
    };

    int l = 0, r = n + 2;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    cout << r << endl;
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
