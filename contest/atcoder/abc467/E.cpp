#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<i64> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n - 1; i++) cin >> b[i];

    vector<i64> k(n, 0);
    for (int i = 1; i < n; i++) {
        int t = ((b[i] - a[i] - a[i + 1]) % m + m) % m;
        if (i & 1) {
            k[i] = (k[i - 1] + t) % m;
        } else {
            k[i] = (k[i - 1] + (m - t) % m) % m;
        }
    }
    i64 s1 = 0, s2 = 0;
    vector<i64> odd, even;

    for (int i = 0; i < n; i++) {
        if (!(i & 1)) {
            odd.push_back(k[i]);
            s1 += k[i];
        } else {
            even.push_back(k[i]);
            s2 += k[i];
        }
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    vector<i64> cand(1, 0);

    for (int i = 1; i <= n; i++) {
        cand.push_back(k[i - 1]);
    }

    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());

    i64 ans = 1e18;

    for (auto val : cand) {
        i64 tot = 0;
        auto it = upper_bound(odd.begin(), odd.end(), val);
        int t1 = odd.end() - it;
        tot += (val * (i64)odd.size() - s1 + t1 * m);

        auto it2 = lower_bound(even.begin(), even.end(), val);
        int t2 = it2 - even.begin();
        tot += (s2 - val * (i64)even.size() + t2 * m);
        ans = min(ans, tot);
    }

    cout << ans;
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