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

    i64 ans1 = 0, ans2 = 0;

    for (int i = 1; i <= n; i++) {
        if (!(__builtin_popcountll(w[i]) & 1)) {
            ans1 += w[i];
        } else {
            ans2 += w[i];
        }
    }

    cout << max(ans1, ans2) << '\n';
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