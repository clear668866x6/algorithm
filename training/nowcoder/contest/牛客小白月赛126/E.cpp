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
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    int ans = 1e18;

    string s = to_string(x);
    int n = sz(s);
    s = ' ' + s;

    FOR(i, 0, n) {
        int p = 1005;
        string t1 = s;
        FOR(j, 1, i) {
            t1.pop_back();
        }
        int cur = 0;
        FOR(i, 1, sz(t1) - 1) cur = cur * 10 + t1[i] - '0';
        FOR(j, 0, 5) {
            if (i == n - 4) {
                if (cur == p + j) {
                    cout << 0 << endl;
                    RE;
                }
            }
            int curl = p + j, curr = p + j + 1;
            FOR(k, 0, 12) {
                int del2 = curl - cur, del3 = curr - 1 - cur;
                int tl = (del2 + c - 1) / c, tr = del3 / c;
                if (tl <= tr && tl > 0) {
                    ans = min(ans, a * i + b * tl);
                }
                curl *= 10;
                curr *= 10;
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
