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
    int a, b, c;
    cin >> a >> b >> c;
    if (max({a, b, c}) != a) {
        cout << -1 << endl;
    } else {
        V<int> ans(a + 3, 0);
        int t = min(b, c);
        FOR(i, 1, 2 + t) {
            ans[i] = 2;
        }

        if (b > c) {
            int del = b - c;
            FOR2(i, t + 3, t + 3 + del - 1, 3) {
                ans[i] = 4;
                if (i + 1 <= t + 3 + del - 1) ans[i + 1] = 2;
                if (i + 2 <= t + 3 + del - 1) ans[i + 2] = 2;
            }

            FOR2(i, t + 3 + del, a + 2, 3) {
                ans[i] = 1;
                if (i + 1 <= a + 2) {
                    ans[i + 1] = 2;
                }
                if (i + 2 <= a + 2) {
                    ans[i + 2] = 2;
                }
            }

        } else if (b < c) {
            int del = c - b;
            FOR2(i, t + 3, t + 3 + del - 1, 3) {
                ans[i] = 5;
                if (i + 1 <= t + 3 + del - 1) ans[i + 1] = 2;
                if (i + 2 <= t + 3 + del - 1) ans[i + 2] = 2;
            }
            int p = t + 3 + del - 1;
            if (ans[p] == 2 && ans[p - 1] == 2) {
                FOR2(i, t + 3 + del, a + 2, 3) {
                    ans[i] = 1;
                    if (i + 1 <= a + 2) {
                        ans[i + 1] = 2;
                    }
                    if (i + 2 <= a + 2) {
                        ans[i + 2] = 2;
                    }
                }

            } else if (ans[p - 1] == 5 && ans[p] == 2) {
                FOR2(i, t + 3 + del, a + 2, 3) {
                    ans[i] = 4;
                    if (i + 1 <= a + 2) {
                        ans[i + 1] = 1;
                    }
                    if (i + 2 <= a + 2) {
                        ans[i + 2] = 2;
                    }
                }
            } else {
                FOR2(i, t + 3 + del, a + 2, 3) {
                    ans[i] = 4;
                    if (i + 1 <= a + 2) {
                        ans[i + 1] = 2;
                    }
                    if (i + 2 <= a + 2) {
                        ans[i + 2] = 1;
                    }
                }
            }
        } else {
            FOR2(i, t + 3, a + 2, 3) {
                ans[i] = 1;
                if (i + 1 <= a + 2) {
                    ans[i + 1] = 2;
                }
                if (i + 2 <= a + 2) {
                    ans[i + 2] = 2;
                }
            }
        }

        cout << a + 2 << endl;
        FOR(i, 1, a + 2) cout << ans[i] << ' ';
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