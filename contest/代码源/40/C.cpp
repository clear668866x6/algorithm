#include <bits/stdc++.h>
using namespace std;

// #define int int64_t
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
    int n, m, k;
    cin >> n >> m >> k;
    V<V<char>> s(n + 1, V<char>(m + 1, 0));
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> s[i][j];
        }
    }

    V<V<char>> ans(n + 1, V<char>(m + 1, '.'));

    FOR(j, 1, m) {
        V<int> c(1, 0);
        FOR(i, 1, n) {
            if (s[i][j] == '-') {
                c.eb(i);
            }
        }
        c.eb(n + 1);
        FORD(a, 1, sz(c) - 1) {
            if (c[a] - c[a - 1] == 1) continue;
            int l = c[a - 1], r = c[a];
            int top = r;
            FORD(b, l + 1, r - 1) {
                if (s[b][j] != '.') {
                    if (top - 1 - b > k) {
                        ans[--top][j] = '*';
                    } else {
                        ans[--top][j] = s[b][j];
                    }
                }
            }
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (s[i][j] == '-') ans[i][j] = '-';
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cout << ans[i][j];
        }
        cout << endl;
    }
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