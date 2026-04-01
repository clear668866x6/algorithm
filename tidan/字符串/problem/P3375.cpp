#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    s = ' ' + s, t = ' ' + t;

    vector<int> nxt(m + 1, 0);

    int j = 0;
    for (int i = 2; i <= m; i++) {
        while (j > 0 && t[j + 1] != t[i]) j = nxt[j];
        if (t[j + 1] == t[i]) j++;
        nxt[i] = j;
    }

    j = 0;

    for (int i = 1; i <= n; i++) {
        while (j > 0 && t[j + 1] != s[i]) j = nxt[j];
        if (t[j + 1] == s[i]) j++;
        if (j == m) {
            cout << i - m + 1 << "\n";
            j = nxt[j];
        }
    }

    for (int i = 1; i <= m; i++) cout << nxt[i] << ' ';
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