#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);

    vector<int> pos(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
        if (pos[i] != b[i]) {
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