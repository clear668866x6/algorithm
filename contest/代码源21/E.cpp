#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()

void solve () {
    int n;
    cin >> n;

    V<int>sx (n + 1, 0), sy (n + 1, 0), s (n + 1, 0);
    V<char>c (n + 1, 0);

    FOR (i, 1, n) {
        int x;
        cin >> c[i] >> x;
        if (c[i] == 'L') {
            sx[i] = sx[i - 1] - x;
            sy[i] = sy[i - 1];
        } else if (c[i] == 'R') {
            sx[i] = sx[i - 1] + x;
            sy[i] = sy[i - 1];
        } else if (c[i] == 'U') {
            sy[i] = sy[i - 1] + x;
            sx[i] = sx[i - 1];
        } else {
            sy[i] = sy[i - 1] - x;
            sx[i] = sx[i - 1];
        }
        s[i] = s[i - 1] + x;
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r, t;
        cin >> l >> r >> t;
        int delx = sx[l - 1] + sx[n] - sx[r];
        int dely = sy[l - 1] + sy[n] - sy[r];
        int tot = s[l - 1] + s[n] - s[r];
        int a = t / tot, b = t % tot;
        delx *= a, dely *= a;
        if (b <= s[l - 1]) {
            int idx = upper_bound (s.begin () + 1, s.end (), b) - s.begin () - 1;
            if (idx >= 1) {
                delx += sx[idx];
                dely += sy[idx];
                b -= s[idx];
            }
            if (b > 0) {
                if (idx + 1 >= l) {
                    if (r + 1 > n) {
                        idx = 1;
                    } else {
                        idx = r + 1;
                    }
                } else {
                    idx++;
                }
                if (c[idx] == 'L') {
                    delx -= b;
                } else if (c[idx] == 'R') {
                    delx += b;
                } else if (c[idx] == 'U') {
                    dely += b;
                } else {
                    dely -= b;
                }
                b = 0;
            }
        } else {
            int idx = upper_bound (s.begin () + r + 1, s.end (), b - s[l - 1] + s[r]) - s.begin () - 1;
            b -= s[l - 1];
            delx += sx[l - 1], dely += sy[l - 1];
            if (idx > r) {
                delx += sx[idx] - sx[r];
                dely += sy[idx] - sy[r];
                b -= (s[idx] - s[r]);
            }

            if (b > 0) {
                if (idx + 1 > n) {
                    if (l == 1) {
                        idx = r + 1;
                    } else {
                        idx = 1;
                    }
                } else {
                    idx++;
                }
                if (c[idx] == 'L') {
                    delx -= b;
                } else if (c[idx] == 'R') {
                    delx += b;
                } else if (c[idx] == 'U') {
                    dely += b;
                } else {
                    dely -= b;
                }
                b = 0;
            }
        }
        cout << delx << ' ' << dely << endl;

    }

}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}