#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

signed main() {
    int n;
    cin >> n;

    map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        int t = i;
        for (int j = 2; j <= t / j; j++) {
            if (t % j == 0) {
                int c = 0;
                while (t % j == 0) t /= j, c++;
                mp[j] += c;
            }
        }
        if (t > 1) mp[t] += 1;
    }

    int ans = 1;

    for (auto [x, y] : mp) {
        ans *= (y + 1);
        ans %= mod;
    }

    cout << ans;
}