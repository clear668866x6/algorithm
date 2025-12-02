#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    ranges::sort(s);

    int ans = 0;

    do {

        bool f = false;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i]) {
                f = 1;
                break;
            }
        }

        if (!f) {
            ans++;
        }

    } while (next_permutation(s.begin(), s.end()));

    cout << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}