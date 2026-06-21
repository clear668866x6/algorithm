#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    i64 tot = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], tot += a[i];

    vector<i64> s(n + 1, 0);
    set<i64> s2;
    s2.insert(0);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i], s2.insert(s[i]);

    auto calc = [&](i64 x) {
        i128 ans = 0;

        for (int i = 0; i < n; i++) {
            auto it = s2.lower_bound(s[i] + x);
            if (it != s2.end()) {
                ans = max(ans, (i128)(*it - s[i]) * (tot - *it + s[i]));
            }
            if (it != s2.begin()) {
                it--;
                ans = max(ans, (i128)(*it - s[i]) * (tot - *it + s[i]));
            }
        }
        return ans;
    };

    i128 ans = max({calc(tot / 2), calc(tot / 2 + 1), calc(tot / 2 - 1)});

    int res = (ans) % mod;

    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}