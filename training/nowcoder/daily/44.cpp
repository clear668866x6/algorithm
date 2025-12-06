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
    int n, x;
    cin >> n >> x;
    V<int> a(n + 1, 0), b(n + 1, 0);
    FOR(i, 1, n) cin >> a[i], b[i] = a[i];
    if (a[1] == -999) {
        a[1] = 50;
        b[1] = -50;
    }

    int c1 = 0, c2 = 0;

    FOR(i, 2, n) {
        if (a[i] == -999) {
            if (a[i - 1] - x >= -50)
                a[i] = a[i - 1] - x;
            else
                a[i] = 50;
            b[i] = max<int>(-50, b[i - 1] - (x - 1));
        }
    }

    FOR(i, 2, n) {
        if (a[i - 1] - a[i] >= x) c1++;
        if (b[i - 1] - b[i] >= x) c2++;
    }

    cout << c1 << ' ' << c2 << endl;
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