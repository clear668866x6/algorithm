#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;

    int r = 1, tot = 0;

    double ans = 0;

    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (s[i] == 'o');

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'o') {
            r = max(r, i);
            tot++;
            if (tot == k) break;
        }
    }
    ans = max(ans, (double)k / (double)r);

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'o') {
            int j = max(j, r);
            while (j + 1 <= n && sum[j + 1] - sum[i] < tot) j++;
            if (sum[j + 1] - sum[i] == tot) {
                int len = j - i + 1;
                r = j;
                ans = max(ans, (double)k / (double)len);
            }
        } else {
            int len = r - i;
            if (sum[r] - sum[i] == tot) ans = max(ans, (double)k / (double)len);
        }
    }

    cout << fixed << setprecision(12) << ans;
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