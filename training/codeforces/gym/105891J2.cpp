#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int k;
    string s;
    cin >> k >> s;
    int n = s.size();
    s = ' ' + s;

    vector<string> m = {"lose", "lse", "ose", "loe", "los", "lo", "le", "os", "se", "ls", "oe", "l", "o", "s", "e"};

    int ans = 0;

    auto get = [&](string a) {
        int t = a.size();
        for (int i = 1; i <= n; i++) {
            string p;
            for (int j = i; j <= i + t - 1; j++) {
                p += s[j];
            }

            if (p == a) {
                if (k - (4 - t) >= 0) {
                    k -= (4 - t);
                    ans++;
                    for (int j = i; j <= i + t - 1; j++) s[j] = '#';
                }
            }
        }
    };

    for (int i = 0; i < 15; i++) {
        get(m[i]);
    }

    ans += k / 4;

    cout << ans;
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