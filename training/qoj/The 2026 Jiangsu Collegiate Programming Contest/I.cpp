#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();
    s = ' ' + s;
    t = ' ' + t;

    vector<int> la(256, 0), lb(256, 0), ra(256, 0), rb(256, 0);

    for (int i = 1; i <= n; i++) {
        if (!la[s[i]]) {
            la[s[i]] = i;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!lb[t[i]]) {
            lb[t[i]] = i;
        }
    }

    for (int i = n; i >= 1; i--) {
        if (!ra[s[i]]) {
            ra[s[i]] = i;
        }
    }

    for (int i = m; i >= 1; i--) {
        if (!rb[t[i]]) {
            rb[t[i]] = i;
        }
    }

    for (char a = 'a'; a <= 'z'; a++) {
        if (!la[a]) continue;
        for (char b = 'a'; b <= 'z'; b++) {
            int l1 = la[a], r1 = ra[b];
            int l2 = lb[a], r2 = rb[b];
            if ((l1 && r1 && l2 && r2) && (l1 < r1 && l2 < r2)) {
                cout << a << b << '\n';
                return;
            }
        }
    }
    cout << "HENG!\n";
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