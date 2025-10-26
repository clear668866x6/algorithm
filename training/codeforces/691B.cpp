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
    string s;
    cin >> s;
    int n = sz(s);
    s = ' ' + s;

    string p = "AHIMOoTUVvWwXxY";

    FOR(i, 1, n / 2) {
        if (s[i] == 'b' && s[n - i + 1] == 'd' || (s[i] == 'd' && s[n - i + 1] == 'b')) continue;
        if (s[i] == 'p' && s[n - i + 1] == 'q' || (s[i] == 'q' && s[n - i + 1] == 'p')) continue;
        bool f = false;
        FOR(j, 0, sz(p) - 1) {
            if (s[i] == p[j]) {
                f = 1;
                break;
            }
        }
        if (!f) {
            cout << "NIE";
            RE;
        }
        if (s[i] != s[n - i + 1]) {
            cout << "NIE";
            RE;
        }
    }

    if (n & 1) {
        bool f = false;
        FOR(j, 0, sz(p) - 1) {
            if (s[(n + 1) / 2] == p[j]) {
                f = 1;
                break;
            }
        }
        if (!f) {
            cout << "NIE";
            RE;
        }
    }

    cout << "TAK";
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