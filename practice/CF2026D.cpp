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
    V<int> a(n + 1, 0), s(n + 1, 0), s2(n + 1, 0), s3(n + 1, 0), s4(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) s[i] = s[i - 1] + a[i];
    FOR(i, 1, n) s2[i] = s2[i - 1] + s[i];
    FOR(i, 1, n) s3[i] = s3[i - 1] + (n - i) * s[i];
    FOR(i, 1, n) s4[i] = s4[i - 1] + s2[i];

    auto calc = [&](int x) {
        if (!x) return (int)0;
        int l = -1, r = n + 1;
        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            if ((2 * n + 1 - mid) * mid / 2 >= x)
                r = mid;
            else
                l = mid;
        }

        int del = x - (2 * n + 1 - l) * l / 2;
        int t1 = s2[n] * l - s4[max<int>(0, l - 1)] - s3[max<int>(0, l - 1)];
        int t2 = (s2[l + del] - s2[l] - del * s[l]);

        return t1 + t2;
    };

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << calc(r) - calc(l - 1) << endl;
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