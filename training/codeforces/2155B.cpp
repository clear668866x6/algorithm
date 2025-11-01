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
    int n, k;
    cin >> n >> k;

    if ((n * n - k) == 1) {
        NO;
    } else {
        YES;
        V<V<char>> s(n + 1, V<char>(n + 1, 'L'));
        FOR(i, 1, n) s[i][1] = 'R';
        int del = n * n - k;
        V<V<int>> vis(n + 1, V<int>(n + 1, 0));
        FOR(i, 1, n) {
            int t = n;
            if (del >= t) {
                FOR(j, 1, t) vis[i][j] = 1;
                del -= t;
            } else {
                if (i > 1) {
                    FOR(j, 1, del) {
                        s[i][j] = 'U';
                        vis[i][j] = 1;
                    }
                }
                FOR(j, 1, del) vis[i][j] = 1;

                del = 0;
                break;
            }
        }

        FOR(i, 1, n) {
            FOR(j, 1, n) {
                if (vis[i][j]) continue;
                s[i][j] = 'R';
            }
        }

        FOR(i, 1, n) {
            FOR(j, 1, n) {
                cout << s[i][j];
            }
            cout << endl;
        }
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
