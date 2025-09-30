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
    V<int> w(n + 1, 0), s(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    sort(ALL(w));
    FOR(i, 1, n) s[i] = s[i - 1] + w[i];

    int l = -1, r = 1e12;

    auto check = [&](int x) {
        int tot = s[n] - s[1] + (w[1] - x);
        if (tot <= k) return 1;
        int c = 1;
        FORD(i, max<int>(2, n - x + 1), n) {
            int del = (x - c);
            tot = s[i - 1] - s[1] + (w[1] - del) * (c + 1);
            if (tot <= k) return 1;
            c++;
        }
        return 0;
    };

    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
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
