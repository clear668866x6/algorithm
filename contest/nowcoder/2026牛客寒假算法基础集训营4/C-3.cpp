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

    int t = (1ll << n);
    V<int> w(t + 1, 0);

    w[1] = 0, w[2] = 1;
    set<int> s;
    s.insert(0), s.insert(1);

    FOR2(i, 3, t, 2) {
        int l = w[i - 1];
        if (lowbit((i - 1)) == (i - 1)) {
            int p = l | (i - 1);
            w[i] = p;
            if (p & 1) {
                w[i + 1] = p - 1;

            } else {
                w[i + 1] = p + 1;
            }
            s.insert(w[i]), s.insert(w[i + 1]);
        } else {
            V<int> p;
            int t = l;
            while (t) {
                p.eb(t % 2);
                t /= 2;
            }

            auto get = [&](V<int> &pp) {
                int t = 0;
                for (auto x : pp) t = t * 2 + x;
                return t;
            };

            reverse(ALL(p));

            FORD(idx, 0, sz(p) - 2) {
                p[idx] ^= 1;
                if (!s.count(get(p))) {
                    w[i] = get(p);
                    if (w[i] & 1) {
                        w[i + 1] = w[i] - 1;
                    } else {
                        w[i + 1] = w[i] + 1;
                    }

                    s.insert(w[i]), s.insert(w[i + 1]);
                    break;
                }
                p[idx] ^= 1;
            }
        }
    }

    FOR(i, 1, t) cout << w[i] << ' ';
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