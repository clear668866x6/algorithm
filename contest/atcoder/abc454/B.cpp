#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1, 0);
    set<int> s;
    for (int i = 1; i <= n; i++) cin >> w[i], s.insert(w[i]);

    if (s.size() != n) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

    for (int i = 1; i <= m; i++) {
        if (!s.count(i)) {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
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