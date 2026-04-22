#include <bits/stdc++.h>
using namespace std;

#define int long long

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    string s;
    cin >> s;
    n = s.size();
    s = ' ' + s;

    string p1(1, ' '), p2(1, ' ');

    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            p1 += 'a';
            p2 += 'b';
        } else {
            p1 += 'b';
            p2 += 'a';
        }
    }

    auto chk = [&](string p) {
        int cnt = 0, l = n + 1, r = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] != p[i]) {
                l = i;
                break;
            }
        }

        for (int i = n; i >= 1; i--) {
            if (s[i] != p[i]) {
                r = i;
                break;
            }
        }

        bool f1 = false, f2 = false;

        for (int i = l, t = r; i <= r; i++, t--) {
            if (s[i] != p[t]) {
                f1 = 1;
                break;
            }
        }

        string S = s;
        for (int i = l; i <= r; i++) {
            if (S[i] == 'a')
                S[i] = 'b';
            else if (S[i] == 'b')
                S[i] = 'a';
        }

        for (int i = l, t = r; i <= r; i++, t--) {
            if (S[i] != p[t]) {
                f2 = 1;
                break;
            }
        }

        if (f1 && f2) return 0;
        return 1;
    };

    int t = max(chk(p1), chk(p2));
    if (t == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}