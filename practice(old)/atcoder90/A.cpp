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
    int n, L, k;
    cin >> n >> L >> k;
    V<int> a(n + 2, 0);
    FOR(i, 1, n) cin >> a[i];
    a[n + 1] = L;
    int l = 0, r = L + 1;
    k++;

    auto check = [&](int x) {
        int cnt = 0, lst = 0;
        FOR(i, 1, n + 1) {
            if ((a[i] - lst) >= x) {
                lst = a[i];
                cnt++;
            }
        }

        return cnt >= k;
    };

    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    cout << l << endl;
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