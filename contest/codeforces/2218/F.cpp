#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int x, y;
    cin >> x >> y;

    if (x > y) {
        cout << "No\n";
        return;
    }

    if (!x) {
        if (y & 1) {
            cout << "Yes\n";
            for (int i = 2; i <= x + y; i++) {
                cout << "1 " << i << '\n';
            }
        } else {
            cout << "No\n";
        }
    } else {
        cout << "Yes\n";
        if ((y - x) & 1) {
            int j = x + y;
            int del = y - x;
            for (int i = 1; i <= x - 1; i++) {
                cout << j << ' ' << j - 1 << "\n";
                j--;
                if (j - 1 < 0) break;
                cout << j << ' ' << j - 1 << "\n";
                j--;
            }
            cout << j << ' ' << j - 1 << "\n";
            j--;

            for (int i = 2; i <= del + 1; i++) {
                cout << "1 " << i << '\n';
            }
        } else {
            x--;
            int j = x + y + 1;
            int del = y - x;
            set<array<int, 2>> s;
            for (int i = 1; i <= x; i++) {
                s.insert({j - 1, j});
                j--;
                if (j - 1 < 0) break;
                s.insert({j - 1, j});
                j--;
            }
            for (int i = 2; i <= del + 1; i++) {
                s.insert({1, i});
            }

            for (auto [x, y] : s) {
                cout << x << ' ' << y << '\n';
            }
        }
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