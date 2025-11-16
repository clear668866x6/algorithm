#include <bits/stdc++.h>
#include <cctype>
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
    int n = 4;

    V<V<char>> s(n + 1, V<char>(n + 1, 0));
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> s[i][j];
        }
    }

    array<int, 8> dx = {0, 1, 1, 1, 0, -1, -1, -1};
    array<int, 8> dy = {1, 1, 0, -1, -1, -1, 0, 1};

    set<array<int, 2>> st;
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if (isdigit(s[i][j])) {
                FOR(k, 0, 7) {
                    int a = dx[k] + i, b = dy[k] + j;
                    if (a < 1 || b < 1 || a > n || b > n) continue;
                    if (isdigit(s[a][b])) continue;
                    st.insert({a, b});
                }
            }
        }
    }
    V<array<int, 2>> p;
    for (auto [x, y] : st) p.pb({x, y});

    int tot = sz(st);
    V<V<int>> ans(n + 1, V<int>(n + 1, 0));
    bool t = false;

    FOR(state, 0, (1 << tot) - 1) {
        V<V<int>> c(n + 1, V<int>(n + 1, 0));
        FOR(pos, 0, tot - 1) {
            if (state >> pos & 1) {
                auto [x, y] = p[pos];
                c[x][y] = 1;
            }
        }

        bool f = false;
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                if (isdigit(s[i][j])) {
                    int num = s[i][j] - '0';
                    int cnt = 0;
                    FOR(k, 0, 7) {
                        int a = dx[k] + i, b = dy[k] + j;
                        if (a < 1 || b < 1 || a > n || b > n) continue;
                        if (isdigit(s[a][b])) continue;
                        if (c[a][b]) cnt++;
                    }
                    if (cnt != num) {
                        f = 1;
                        break;
                    }
                }
            }
            if (f) break;
        }

        if (!f) {
            if (!t) {
                ans = c;
                t = 1;
            } else {
                FOR(i, 1, n) {
                    FOR(j, 1, n) {
                        if (c[i][j] == 1 && ans[i][j] == 0) {
                            ans[i][j] = 2;
                        } else if (c[i][j] == 0 && ans[i][j] == 1) {
                            ans[i][j] = 2;
                        }
                    }
                }
            }
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if (st.count({i, j})) {
                if (ans[i][j] == 2)
                    cout << ".";
                else if (ans[i][j] == 0)
                    cout << "O";
                else
                    cout << "X";

            } else {
                cout << s[i][j];
            }
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