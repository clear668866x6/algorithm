#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    i64 tot = 0;

    for (int i = 1; i <= n; i++) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        if (s == "keep") {
            tot += (b - a);
        }
    }

    cout << tot;
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