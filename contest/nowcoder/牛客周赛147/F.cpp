#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, x, k;
    cin >> n >> x >> k;

    if (k < n) {
        cout << "NO\n";
        return;
    }

    vector<int> v;

    for (int l = 1, r; l <= x; l = r + 1) {
        int val = x / l;
        v.push_back(val);
        r = x / val;
    }

    sort(v.rbegin(), v.rend());
    v.erase(unique(v.begin(), v.end()), v.end());

    vector<int> ans;
    bool f = false;

    auto dfs = [&](auto &&dfs, int cnt, int val) -> void {
        if (f) return;
        if (val > k || cnt > n) return;

        int rec = n - cnt, rev = k - val;

        if (rec > 0) {
            int mx = ans.empty() ? v.front() : ans.back();
            if ((i64)rec * mx < rev) return;
            if ((i64)rec * v.back() > rev) return;
        }

        if (val == k && cnt == n) {

            cout << "YES\n";
            for (auto y : ans) {
                cout << x / y << ' ';
            }
            cout << "\n";
            f = 1;

            return;
        }

        for (auto t : v) {
            if (!ans.empty() && ans.back() < t) continue;
            ans.push_back(t);
            dfs(dfs, cnt + 1, t + val);
            ans.pop_back();
            if (f) return;
        }
    };

    dfs(dfs, 0, 0);

    if (!f) {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}