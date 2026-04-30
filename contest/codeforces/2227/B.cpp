#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;

    int s1 = 0, s2 = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i] == '(')
            s1++;
        else
            s2++;
    }

    if (s1 != s2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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