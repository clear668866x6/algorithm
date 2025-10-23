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
    cin >> n;

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    map<int, int> mp;

    FOR(i, 1, n) {
        mp[w[i]]++;
    }
    int mx = 0;
    for (auto [x, y] : mp) {
        if (y >= n / 2) {

            cout << -1 << endl;
            RE;
        }
    }
    int ans = 0;
    V<int> tt;

    FOR(i, 1, n) {
        FOR(j, i + 1, n) {
            tt.eb(abs(w[i] - w[j]));
        }
    }
    sort(ALL(tt));

    FORD(p, 0, sz(tt) - 1) {
        if (!tt[p]) continue;
        int dif = tt[p];
        FOR(k, 1, dif / k) {
            if (dif % k == 0) {

                auto calc = [&](int k) {
                    map<int, int> b;
                    int ans = 0;
                    V<int> a(n + 1, 0);
                    FOR(i, 1, n) {
                        a[i] = (w[i] % k + k) % k;
                    }

                    FOR(i, 1, n) {
                        b[a[i]]++;
                        if (b[a[i]] >= n / 2) {
                            ans = k;
                            break;
                        }
                    }
                    if (ans) return ans;
                    return (int)0;
                };
                ans = max(ans, calc(k));
                ans = max(ans, calc(dif / k));
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