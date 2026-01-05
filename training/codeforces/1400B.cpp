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
    int p, f, cs, cw, s, w;
    cin >> p >> f >> cs >> cw >> s >> w;

    int ans = 0;

    FOR(c1, 0, min(cs, p / s)) {
        int c2 = (p - c1 * s) / w;
        if (c2 >= cw) {
            c2 = cw;
            int c3 = f / s;
            if (c3 + c1 >= cs) {
                ans = max(ans, cs + c2);
            } else {
                ans = max(ans, c3 + c1 + c2);
            }
        } else {
            if (s > w) {
                int c4 = min(f / w, cw - c2);
                int t = f - c4 * w;
                int c3 = t / s;
                if (c3 + c1 >= cs) {
                    ans = max(ans, cs + c2 + c4);
                } else {
                    ans = max(ans, c1 + c2 + c3 + c4);
                }

            } else {
                int c3 = min(f / s, cs - c1);
                int t = f - c3 * s;
                int c4 = t / w;
                if (c2 + c4 >= cw) {
                    ans = max(ans, cw + c1 + c3);
                } else {
                    ans = max(ans, c1 + c2 + c3 + c4);
                }
            }
        }
    }

    cout << ans << endl;
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
