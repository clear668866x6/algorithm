#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, q;
    cin >> n >> q;

    while (q--) {
        int x, y;
        string s;
        cin >> x >> y >> s;

        for (auto c : s) {
            if (c == 'f') {
                if (y + 1 <= n) {
                    y++;
                }
            } else if (c == 'b') {
                if (y - 1 >= 1) {
                    y--;
                }
            } else if (c == 'l') {
                if (x - 1 >= 1) {
                    x--;
                }
            } else {
                if (x + 1 <= n) {
                    x++;
                }
            }
        }
        cout << x << ' ' << y << '\n';
    }
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