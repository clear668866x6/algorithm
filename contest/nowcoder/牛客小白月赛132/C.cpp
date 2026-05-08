#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    i64 l, r;
    cin >> l >> r;

    auto calc = [&](i64 x) {
        int len = 0;
        i64 y = x;
        while (y) {
            len++;
            y /= 2;
        }

        i64 tot = (len - 1) * (len - 2) / 2;
        int cnt = 0;
        tot += (len - 1);

        for (int i = 63; i >= 0; i--) {
            if (x >> i & 1) {
                cnt++;
                if (cnt == 2) {
                    tot += i + 1;
                    break;
                }
            }
        }
        return tot;
    };

    cout << calc(r) - calc(max(0ll, l - 1)) << '\n';
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