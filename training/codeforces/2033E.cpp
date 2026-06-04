#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];

    vector<int> siz(n + 1, 1), p(n + 1, 0);
    iota(p.begin(), p.end(), 0ll);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    for (int i = 1; i <= n; i++) {
        int a = i, b = w[i];
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            siz[b] += siz[a];
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            ans += (siz[i] - 1) / 2;
        }
    }

    cout << ans << '\n';
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