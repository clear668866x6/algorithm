#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    i64 ans = 0;

    auto chk = [&](int l, int x) {
        cout << "? " << l << ' ' << x << endl;
        string s;
        cin >> s;
        if (s == "Yes") return 1;
        return 0;
    };

    int r = 1;

    for (int l = 1; l <= n - 1; l++) {
        r = max(r, l);
        while (r + 1 <= n && chk(l, r + 1)) r++;
        ans += (r - l);
    }

    cout << "! " << ans << endl;
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