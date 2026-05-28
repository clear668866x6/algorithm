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

    if (!(n & 1)) {
        i64 tot = 0;
        for (int i = 1; i <= n; i++) tot += w[i];
        if (tot & 1) {
            cout << "Insight\n";
        } else {
            cout << "Maya\n";
        }
    } else {
        cout << "Insight\n";
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