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
    string s;
    cin >> n >> m >> s;
    s = ' ' + s;

    V<V<int>> sum(n + 1, V<int>(32, 0));
    V<V<int>> pre(n + 1, V<int>(32, 0)), suf(n + 2, V<int>(32, 0));

    FOR(i, 1, n) {
        FOR(j, 0, 30) {
            sum[i][j] = sum[i - 1][j] + ((s[i] - 'a') != j);
        }
    }

    FOR(j, 0, 30) {
        FOR(i, 1, n) {
            if (s[i] - 'a' == j) {
                pre[i][j] = pre[i - 1][j] + 1;
            } else {
                pre[i][j] = 0;
            }
        }
        FORD(i, 1, n) {
            if (s[i] - 'a' == j) {
                suf[i][j] = suf[i + 1][j] + 1;
            } else {
                suf[i][j] = 0;
            }
        }
    }

    int ans = 0;

    if (!m) {
        FOR(k, 0, 30) {
            int j = 1;
            FOR(i, 1, n) {
                ans = max(ans, pre[i - 1][k] + suf[i][k]);
            }
        }
    } else {
        FOR(k, 0, 30) {
            int j = 1;
            FOR(i, 1, n) {
                while (j + 1 <= n && sum[j][k] - sum[i - 1][k] < m) j++;
                ans = max(ans, pre[i - 1][k] + suf[j + 1][k] + (j - i + 1));
            }
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