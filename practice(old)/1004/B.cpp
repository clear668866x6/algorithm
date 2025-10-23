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
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    int l = 0, r = n + 1;

    int ansl = 1, ansr = n;

    auto check = [&](int x) {
        V<int> s(n + 1, 0);

        FOR(i, 1, n) {
            if (w[i] <= x)
                s[i] = s[i - 1] - 1;
            else
                s[i] = s[i - 1] + 1;
        }

        int mn = 0;
        FOR(i, k, n) {
            if (s[i - k] < s[mn]) {
                mn = i - k;
            }
            if (s[i] - s[mn] >= 0) {
                ansl = mn + 1, ansr = i;
                return 1;
            }
        }
        return 0;
    };

    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    cout << r << ' ' << ansl << ' ' << ansr << endl;
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
