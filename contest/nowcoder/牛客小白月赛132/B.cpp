#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    map<char, int> mp;
    map<char, int> idx;
    vector<char> c(n + 1, 0);
    vector<int> val(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> val[i];
        if (mp[c[i]] < val[i]) {
            mp[c[i]] = val[i];
            idx[c[i]] = i;
        }
    }

    int tot = 0, r = 70 * 6;

    for (char i = 'A'; i <= 'F'; i++) {
        if (mp[i] < 60) {
            cout << -1;
            return;
        }

        tot += mp[i];
    }

    if (tot < r) {
        cout << -1;
    } else {
        for (char i = 'A'; i <= 'F'; i++) {
            cout << idx[i] << ' ';
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