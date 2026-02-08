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
    V<string> s(k + 1);
    FOR(i, 1, k) cin >> s[i], s[i] = ' ' + s[i];

    V<V<int>> cnt(n + 1, V<int>(30, 0));

    FOR(i, 1, n) {
        FOR(j, 1, k) {
            cnt[i][s[j][i] - 'a']++;
        }
    }

    FOR(i, 1, n) {
        if (n % i == 0) {
            string ans;
            int l = 1, r = i;
            bool f3 = false;
            FOR(idx, l, r) {
                bool f2 = false;
                FOR(c, 'a', 'z') {
                    bool f = false;
                    FOR2(t, idx, n, i) {
                        if (!cnt[t][c - 'a']) {
                            f = 1;
                            break;
                        }
                    }
                    if (!f) {
                        ans += c;
                        f2 = 1;
                        break;
                    }
                }
                if (!f2) {
                    f3 = 1;
                    break;
                }
            }
            if (!f3) {
                int p = n / i;
                while (p--) {
                    cout << ans;
                }
                cout << endl;
                RE;
            }
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
