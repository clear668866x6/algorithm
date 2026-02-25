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

    string s = to_string(n);

    int t1 = 0;
    for (auto v : s) {
        t1 += (v - '0');
    }

    int t2 = 0;
    string p = to_string(t1);
    for (auto v : p) {
        t2 += (v - '0');
    }
    if (t1 == t2) {
        cout << 0 << endl;
        RE;
    }

    FOR(ans, 1, 100) {
        char mx = 0;
        FOR(i, 0, sz(s) - 1) {
            mx = max(mx, s[i]);
        }

        FORD(i, 0, sz(s) - 1) {
            if (s[i] == mx) {
                if (i != 0) {
                    s[i] = '0';
                    break;
                } else {
                    s[i] = '1';
                }
            }
        }

        int t1 = 0;
        for (auto v : s) {
            t1 += (v - '0');
        }

        int t2 = 0;
        string p = to_string(t1);
        for (auto v : p) {
            t2 += (v - '0');
        }
        if (t1 == t2) {
            cout << ans << endl;
            RE;
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
