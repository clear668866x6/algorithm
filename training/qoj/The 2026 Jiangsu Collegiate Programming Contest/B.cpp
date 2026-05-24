#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int x;
    cin >> x;

    int t = (int)sqrt(x);

    auto calc = [&](int a, int b) {
        int p = x - a * b;
        if (p < 0) return (int)1e9 + 10;
        return max({a, b, p}) - min({a, b, p});
    };

    int mn = calc(t, t);

    for (int i = -300; i <= 300; i++) {
        int a = t + i;
        if (!a) continue;
        int b = x / a;
        for (int j = -1; j <= 1; j++) {
            mn = min(mn, calc(a, b + j));
        }
    }

    cout << mn << '\n';
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