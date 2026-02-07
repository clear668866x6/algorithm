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
    V<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    int t = 0;
    FOR(i, 1, n) t ^= a[i];
    FOR(i, 1, n) c[i] = a[i] ^ b[i];

    V<int> base(35, 0), num(35, 0), idx(35, 0);
    int cnt = 0;

    FOR(i, 1, n) {
        int x = c[i];
        int state = 0;
        FORD(j, 0, 32) {
            int v = x >> j & 1;
            if (v == 1) {
                if (!num[j]) {
                    num[j] = v;
                    base[j] = state | (1ll << cnt);
                    idx[cnt] = i;
                    cnt++;
                    break;
                }

                x ^= num[j];
                state ^= base[j];
            }
        }
    }

    int cur = 0;
    FORD(i, 0, 32) {
        int v = t >> i & 1;
        if (v == 1) {
            if (!num[i]) {
                cout << -1 << endl;
                RE;
            }
            t ^= num[i];
            cur ^= base[i];
        }
    }

    if (t != 0) {
        cout << -1 << endl;
    } else {
        V<int> vis(n + 1, 0);
        FOR(i, 0, cnt - 1) {
            if (cur >> i & 1) {
                vis[idx[i]] = 1;
            }
        }

        FOR(i, 1, n) {
            if (vis[i])
                cout << b[i] << ' ';
            else
                cout << a[i] << ' ';
        }
        cout << endl;
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
