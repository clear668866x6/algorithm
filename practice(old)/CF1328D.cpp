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

    V<int> w(n, 0), c;

    map<int, int> mp;
    for (auto &x : w) cin >> x, mp[x]++;
    c = w;
    int t = unique(ALL(c)) - c.begin();

    if (mp[w[0]] == n) {
        cout << 1 << endl;
        for (auto x : w) {
            cout << "1 ";
        }
        cout << endl;
        RE;
    }

    V<int> ans(n, 0);

    if (w[0] == w[n - 1]) {
        if (t & 1) {
            cout << 2 << endl;
            ans[0] = 1;
            ans[n - 1] = 1;
            FOR(i, 1, n - 2) {
                if (w[i] == w[i - 1]) {
                    ans[i] = ans[i - 1];
                } else {
                    ans[i] = ((ans[i - 1] - 1) ^ 1) + 1;
                }
            }
        } else {
            cout << 2 << endl;
            ans[0] = 1;
            FOR(i, 1, n - 1) {
                if (w[i] == w[i - 1]) {
                    ans[i] = ans[i - 1];
                } else {
                    ans[i] = ((ans[i - 1] - 1) ^ 1) + 1;
                }
            }
        }

        for (auto x : ans) cout << x << ' ';
        cout << endl;
        RE;
    }

    if (n == t) {
        if (n & 1) {
            cout << 3 << endl;
            ans[0] = 1;
            FOR(i, 1, n - 2) {
                ans[i] = ((ans[i - 1] - 1) ^ 1) + 1;
            }
            ans[n - 1] = 3;
        } else {
            cout << 2 << endl;
            ans[0] = 1;
            FOR(i, 1, n - 1) ans[i] = ((ans[i - 1] - 1) ^ 1) + 1;
        }
    } else {
        if (t & 1) {
            cout << 2 << endl;
            ans[0] = 1;
            bool f = false;
            FOR(i, 1, n - 1) {
                if (w[i] == w[i - 1] && !f) {
                    f = 1;
                    ans[i] = ((ans[i - 1] - 1) ^ 1) + 1;
                } else if (w[i] != w[i - 1]) {
                    ans[i] = ((ans[i - 1] - 1) ^ 1) + 1;
                } else {
                    ans[i] = ans[i - 1];
                }
            }
        } else {
            cout << 2 << endl;
            ans[0] = 1;
            FOR(i, 1, n - 1) {
                if (w[i] == w[i - 1]) {
                    ans[i] = ans[i - 1];
                } else {
                    ans[i] = ((ans[i - 1] - 1) ^ 1) + 1;
                }
            }
        }
    }

    for (auto x : ans) cout << x << ' ';
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
