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
    string s;
    cin >> n >> s;
    s = ' ' + s;

    int c0 = 0, c1 = 0;
    set<array<int, 2>> mt[2];
    V<int> a, b;
    int i1 = 0, i2 = 0;
    FOR(i, 1, n) {
        if (s[i] == '1') {
            if (c0) {
                mt[0].insert({c0, i1++});
                a.eb(c0);
                c0 = 0;
            }
            c1++;
        } else {
            if (c1) {
                mt[1].insert({c1, i2++});
                b.eb(c1);
                c1 = 0;
            }
            c0++;
        }
    }
    if (c0) {
        mt[0].insert({c0, i1++});
        a.eb(c0);
    } else {
        mt[1].insert({c1, i2++});
        b.eb(c1);
    }

    s.erase(unique(ALL(s)), s.end());

    n = sz(s) - 1;
    int ans = 0;
    int idx1 = 0, idx2 = 0;

    FOR(i, 1, n) {
        if (s[i] == '1') {
            ans++;
            if (b[idx2] >= 2) {
                if (i == 3) {
                    cout << "fuck" << endl;
                }
                mt[1].erase(mt[1].find({b[idx2], idx2}));
            } else {
                mt[1].erase(mt[1].find({b[idx2], idx2}));
                int p1 = 0;
                if (sz(mt[1])) {
                    p1 = (*mt[1].rbegin())[0];
                }
                int p2 = 0;
                if (sz(mt[0])) {
                    p2 = (*mt[0].rbegin())[0];
                }
                if (p1 >= p2 && p1 >= 2) {
                    int t = (*mt[1].rbegin())[1];
                    b[t]--;
                    mt[1].erase(mt[1].find(*mt[1].rbegin()));
                    mt[1].insert({b[t], t});
                } else if (p2 >= p1 && p2 >= 2) {
                    int t = (*mt[0].rbegin())[1];
                    a[t]--;
                    mt[0].erase(mt[0].find(*mt[0].rbegin()));
                    mt[0].insert({a[t], t});
                } else if (p1 >= 2) {
                    int t = (*mt[1].rbegin())[1];
                    b[t]--;
                    mt[1].erase(mt[1].find(*mt[1].rbegin()));
                    mt[1].insert({b[t], t});
                } else if (p2 >= 2) {
                    int t = (*mt[0].rbegin())[1];
                    a[t]--;
                    mt[0].erase(mt[0].find(*mt[0].rbegin()));
                    mt[0].insert({a[t], t});
                } else {
                    if (sz(mt[0])) {
                        mt[0].erase(mt[0].find({a[idx1], idx1}));
                        idx1++;
                    }
                    i++;
                }
            }
            idx2++;
        } else {
            ans++;
            if (a[idx1] >= 2) {
                mt[0].erase(mt[0].find({a[idx1], idx1}));
            } else {
                mt[0].erase(mt[0].find({a[idx1], idx1}));
                int p1 = 0;
                if (sz(mt[0])) {
                    p1 = (*mt[0].rbegin())[0];
                }
                int p2 = 0;
                if (sz(mt[1])) {
                    p2 = (*mt[1].rbegin())[0];
                }

                if (p1 >= p2 && p1 >= 2) {
                    int t = (*mt[0].rbegin())[1];
                    a[t]--;
                    mt[0].erase(mt[0].find(*mt[0].rbegin()));
                    mt[0].insert({a[t], t});
                } else if (p2 >= p1 && p2 >= 2) {
                    int t = (*mt[1].rbegin())[1];
                    b[t]--;
                    mt[1].erase(mt[1].find(*mt[1].rbegin()));
                    mt[1].insert({b[t], t});
                } else if (p1 >= 2) {
                    int t = (*mt[0].rbegin())[1];
                    a[t]--;
                    mt[0].erase(mt[0].find(*mt[0].rbegin()));
                    mt[0].insert({a[t], t});
                } else if (p2 >= 2) {
                    int t = (*mt[1].rbegin())[1];
                    b[t]--;
                    mt[1].erase(mt[1].find(*mt[1].rbegin()));
                    mt[1].insert({b[t], t});
                } else {
                    if (sz(mt[1])) {
                        mt[1].erase(mt[1].find({b[idx2], idx2}));
                        idx2++;
                    }
                    i++;
                }
            }
            idx1++;
        }
        cout << "round= " << i << endl;
        cout << "solve = " << sz(mt[0]) << endl;
        for (auto [x, y] : mt[0]) cout << x << ' ';
        cout << endl;
        cout << sz(mt[1]) << endl;
        for (auto [x, y] : mt[1]) cout << x << ' ';
        cout << endl;
        cout << "----------------------" << endl;
    }

    if (sz(mt[1]) || sz(mt[0])) ans++;

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
