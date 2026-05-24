#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n = 72;
    string s;
    cin >> s;
    s = ' ' + s;
    if (s[1] == '1') {
        auto get = [&](int x) {
            if (x == 0)
                return ' ';
            else if (x >= 1 && x <= 10)
                return char('0' + x - 1);
            else if (x <= 36)
                return char('A' + x - 11);
            return '_';
        };

        i64 x = 0;
        for (int i = 2; i <= 59; i++) {
            x = x * 2 + (s[i] - '0');
        }

        i64 t = 38;
        string a1;
        while (x) {
            a1 += get(x % 38);
            x /= t;
        }

    } else {
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