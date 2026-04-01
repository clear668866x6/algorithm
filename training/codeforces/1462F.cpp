#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct BIT {
    vector<int> tr;
    int n;
    BIT() {}
    BIT(int _n) {
        tr.resize(_n, 0);
        n = _n;
    }

    void add(int x, int c) {
        for (int i = x; i <= n; i += i & (-i)) tr[i] += c;
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= i & (-i)) ans += tr[i];
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> w(n);
    vector<int> p, p2;
    for (auto &[l, r] : w) {
        cin >> l >> r;
        p.push_back(l);
        p2.push_back(r), p2.push_back(l), p2.push_back(l - 1);
    }

    BIT A(n * 3 + 10);

    sort(w.begin(), w.end());
    sort(p.begin(), p.end());
    sort(p2.begin(), p2.end());
    p2.erase(unique(p2.begin(), p2.end()), p2.end());
    auto get = [&](int x) { return lower_bound(p2.begin(), p2.end(), x) - p2.begin() + 1; };

    int ans = n;

    for (auto [l, r] : w) {
        auto it = upper_bound(p.begin(), p.end(), r);
        int t1 = p.end() - it;
        int t2 = A.query(get(l - 1));
        A.add(get(r), 1);
        ans = min(ans, t1 + t2);
    }

    cout << ans << "\n";
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