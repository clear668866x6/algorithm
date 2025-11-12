#include <algorithm>
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
    set<int> mt;
    V<int> a(n + 1, 0);
    int i3 = 1;
    FOR(i, 1, n) {
        if (s[i] == '1') {
            if (c0) {
                if (c0 > 1) {
                    mt.insert(i3);
                }
                a[i3] = c0;
                i3++;
                c0 = 0;
            }
            c1++;
        } else {
            if (c1) {
                if (c1 > 1) {
                    mt.insert(i3);
                }
                a[i3] = c1;
                i3++;
                c1 = 0;
            }
            c0++;
        }
    }
    if (c0) {
        if (c0 > 1) {
            mt.insert(i3);
        }
        a[i3] = c0;
    }
    if (c1) {
        if (c1 > 1) {
            mt.insert(i3);
        }
        a[i3] = c1;
    }

    s.erase(unique(ALL(s)), s.end());

    n = sz(s) - 1;
    int ans = 0;

    FOR(i, 1, n) {
        if (s[i] == '1') {
            ans++;
            if (a[i] == 1) {
                if (mt.empty()) {
                    i++;
                    continue;
                }
                auto it = mt.upper_bound(i);
                if (it == mt.end()) {
                    i++;
                } else {
                    int t = *it;
                    a[t]--;
                    if (a[t] == 1) {
                        mt.erase(mt.find(t));
                    }
                }
            }
        } else {
            ans++;
            if (a[i] == 1) {
                if (mt.empty()) {
                    i++;
                    continue;
                }
                auto it = mt.upper_bound(i);
                if (it == mt.end()) {
                    i++;
                } else {
                    int t = *it;
                    a[t]--;
                    if (a[t] == 1) {
                        mt.erase(mt.find(t));
                    }
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
