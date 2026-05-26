#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;

    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            for (int i = 1; i < n; i++) {
                cout << "&";
            }
            return;
        }
    }

    cout << "^";
    for (int i = 1; i < n - 1; i++) cout << "&";
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