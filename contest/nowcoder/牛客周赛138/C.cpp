#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    i64 ans = 0;

    auto change = [&](i64 x) {
        i64 cnt = 0;
        while (x) {
            cnt += (x % 10);
            x /= 10;
        }
        return cnt;
    };

    for (int i = n; i >= 2; i--) {
        i64 t = a[i - 1];
        i64 cnt = 0;
        while (a[i] < t) {
            cnt++;
            ans++;
            if (cnt > 100) {
                cout << "-1\n";
                return;
            }
            t = change(t);
        }
        a[i - 1] = t;
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