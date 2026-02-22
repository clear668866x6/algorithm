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
    int n, k;
    cin >> n >> k;
    V<int> a(n + 1, 0);
    V<int> b(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    set<int> s;
    int mxx = 0;
    FOR(i, 1, n) {
        if (a[i]) {
            s.insert(i);
            mxx = i;
            b[i] = i + a[i];
        }
    }

    if (s.empty()) {
        cout << 0 << endl;
        RE;
    }

    int l = -1, r = n + 1;
    int fs = 1;

    FOR(i, 1, n) {
        if (a[i]) {
            fs = i;
            break;
        }
    }

    V<int> nxt(n + 1, 0);

    FOR(i, 1, n) {
        if (b[i]) {
            auto it = prev(s.upper_bound(b[i]));
            nxt[i] = max(nxt[i - 1], *it);
        } else {
            nxt[i] = nxt[i - 1];
        }
    }

    auto check = [&](int x) {
        int c = 0, t = 1;
        int idx = fs, lst = fs;
        while (idx < mxx) {
            int mx = nxt[idx];
            if (!mx || idx >= mx) {
                auto it = s.upper_bound(idx);
                t++;
                c = 0;
                lst = idx = *it;
                continue;
            }
            c++;
            if (c > x) {
                c = 0;
                t++;
                lst = idx = *s.upper_bound(idx);
            } else {
                lst = idx, idx = mx;
            }
        }

        if (t <= k) return 1;
        return 0;
    };

    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    if (r > n) r = -1;
    cout << r << endl;
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
