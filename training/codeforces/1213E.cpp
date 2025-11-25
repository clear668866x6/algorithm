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
    string a, b;
    cin >> n >> a >> b;

    YES;

    if (a == b) {
        if (a[0] == a[1]) {
            bool f = false;
            FOR(c, 'a', 'c') {
                if (a[0] == c) continue;
                if (!f) {
                    FOR(i, 1, n) {
                        cout << char(c) << a[0];
                    }
                    f = 1;
                } else {
                    FOR(i, 1, n) {
                        cout << char(c);
                    }
                }
            }
        } else {
            char c1 = a[1], c2 = a[0];
            FOR(i, 1, n) cout << c1;
            FOR(i, 1, n) cout << c2;
            FOR(c, 'a', 'c') {
                if (c == c1 || c == c2) continue;
                FOR(i, 1, n) {
                    cout << char(c);
                }
            }
        }
    } else {
        if (a[0] == a[1] && b[0] == b[1]) {
            char c1 = a[0], c2 = b[0];
            FOR(i, 1, n) cout << c1 << c2;
            FOR(c, 'a', 'c') {
                if (c == c1 || c == c2) continue;
                FOR(i, 1, n) {
                    cout << char(c);
                }
            }
        } else if (a[0] == a[1]) {
            char c1 = b[1], c2 = b[0];
            if (c1 == a[0]) {
                FOR(c, 'a', 'c') {
                    if (c == c1 || c == c2) continue;
                    FOR(i, 1, n) {
                        cout << c1 << char(c);
                    }
                }
                FOR(i, 1, n) cout << c2;
            } else if (c2 == a[1]) {
                FOR(c, 'a', 'c') {
                    if (c == c1 || c == c2) continue;
                    FOR(i, 1, n) {
                        cout << c2 << char(c);
                    }
                }
                FOR(i, 1, n) cout << c1;
            } else {

                FOR(i, 1, n) cout << c1 << a[0];
                FOR(i, 1, n) cout << c2;
            }
        } else if (b[0] == b[1]) {
            char c1 = a[1], c2 = a[0];
            if (c1 == b[0]) {
                FOR(c, 'a', 'c') {
                    if (c == c1 || c == c2) continue;
                    FOR(i, 1, n) {
                        cout << c1 << char(c);
                    }
                }
                FOR(i, 1, n) cout << c2;
            } else if (c2 == b[0]) {
                FOR(c, 'a', 'c') {
                    if (c == c1 || c == c2) continue;
                    FOR(i, 1, n) {
                        cout << c2 << char(c);
                    }
                }
                FOR(i, 1, n) cout << c1;
            }

            else {
                FOR(i, 1, n) cout << c1 << b[0];
                FOR(i, 1, n) cout << c2;
            }
        } else {
            char p = 0;
            FOR(c, 'a', 'c') {
                if (c == a[0] || c == a[1] || c == b[0] || c == b[1]) continue;
                p = c;
            }
            if (p == 0) {
                char c1 = a[1], c2 = a[0], c3 = b[1], c4 = b[0];
                map<char, int> mp;
                mp[c1]++, mp[c2]++, mp[c3]++, mp[c4]++;

                FOR(c, 'a', 'c') {
                    if (mp[c] == 2) {
                        if (c1 == c) {
                            if (c3 == c) { // 11
                                FOR(i, 1, n) cout << char(c);
                                FOR(i, 1, n) cout << c2;
                                FOR(i, 1, n) cout << c4;
                            } else { // 12
                                FOR(i, 1, n) cout << c3;
                                FOR(i, 1, n) cout << char(c);
                                FOR(i, 1, n) cout << c2;
                            }
                        } else {
                            if (c3 == c) { // 21
                                FOR(i, 1, n) cout << c1;
                                FOR(i, 1, n) cout << char(c);
                                FOR(i, 1, n) cout << c4;
                            } else { // 22
                                FOR(i, 1, n) cout << c1;
                                FOR(i, 1, n) cout << c3;
                                FOR(i, 1, n) cout << char(c);
                            }
                        }
                        break;
                    }
                }

            } else {
                char c1 = a[0], c2 = a[1];
                FOR(i, 1, n) cout << c1 << p;
                FOR(i, 1, n) cout << c2;
            }
        }
    }
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