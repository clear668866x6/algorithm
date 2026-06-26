#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int a, b;
    cin >> a >> b;

    int tot = a + 2 * b;

    if (tot & 1) {
        cout << "NO";
    } else {
        int t = tot / 2;
        int use = t / 2;
        if (b <= use) {
            int p = t - b * 2;
            if (p > a) {
                cout << "NO";
            } else {
                cout << "YES";
            }
        } else {
            if (t & 1) {
                if (a) {
                    cout << "YES";
                } else {
                    cout << "NO";
                }
            } else {
                cout << "YES";
            }
        }
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