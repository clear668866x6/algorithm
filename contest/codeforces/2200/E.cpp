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
    int n;
    cin >> n;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    bool f = false;
    FOR(i, 2, n) {
        if (w[i - 1] > w[i]) {
            f = 1;
            break;
        }
    }

    if (!f) {
        cout << "Bob" << endl;
    } else {
        V<int> p;
        FOR(i, 1, n) {
            int t = w[i];
            int cnt = 0;
            FOR(j, 2, t / j) {
                if (t % j == 0) {
                    cnt++;
                    while (t % j == 0) t /= j;
                }
            }
            if (t > 1) cnt++;

            if (cnt >= 2) {
                cout << "Alice" << endl;
                RE;
            }
            if (cnt == 1) {
                t = w[i];
                FOR(j, 2, t / j) {
                    if (t % j == 0) {
                        p.eb(j);
                        while (t % j == 0) t /= j;
                    }
                }
                if (t > 1) p.eb(t);
            } else {
                p.eb(1);
            }
        }

        FOR(i, 1, sz(p) - 1) {
            if (p[i - 1] > p[i]) {
                cout << "Alice" << endl;
                RE;
            }
        }
        cout << "Bob" << endl;
    }
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
