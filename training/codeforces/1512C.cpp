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
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = sz(s);
    s = ' ' + s;

    FOR(i, 1, n / 2) {
        if (s[i] == '1') {
            if (s[n - i + 1] == '?') {
                s[n - i + 1] = '1';
                b -= 2;
            } else if (s[n - i + 1] == '0') {
                cout << -1 << endl;
                RE;
            } else {
                b -= 2;
            }
        } else if (s[i] == '0') {
            if (s[n - i + 1] == '?') {
                a -= 2;
                s[n - i + 1] = '0';
            } else if (s[n - i + 1] == '1') {
                cout << -1 << endl;
                RE;
            } else {
                a -= 2;
            }
        } else {
            if (s[n - i + 1] == '1') {
                s[i] = '1';
                b -= 2;
            } else if (s[n - i + 1] == '0') {
                s[i] = '0';
                a -= 2;
            }
        }
    }

    if (a < 0 || b < 0) {
        cout << -1 << endl;
        RE;
    }

    FOR(i, 1, n / 2) {
        if (s[i] == '?') {
            if (a >= 2) {
                a -= 2;
                s[i] = s[n - i + 1] = '0';
            } else if (b >= 2) {
                b -= 2;
                s[i] = s[n - i + 1] = '1';
            } else {
                cout << -1 << endl;
                RE;
            }
        }
    }

    if (n & 1) {
        if (s[n / 2 + 1] == '?') {
            if (a) {
                s[n / 2 + 1] = '0';
            } else if (b) {
                s[n / 2 + 1] = '1';
            } else {
                cout << -1 << endl;
                RE;
            }

        } else if (s[n / 2 + 1] == '0') {
            if (!a) {
                cout << -1 << endl;
                RE;
            }
        } else {
            if (!b) {
                cout << -1 << endl;
                RE;
            }
        }
    }

    FOR(i, 1, n) cout << s[i];
    cout << endl;
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
