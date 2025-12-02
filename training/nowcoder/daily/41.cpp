#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

struct Prime {
    static constexpr int N = 1e6 + 10;

    int primes[N], cnt;
    bool vis[N];
    int s[N];

    void init() {
        int n = N - 10;
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) primes[cnt++] = i;
            for (int j = 0; i * primes[j] <= n; j++) {
                vis[i * primes[j]] = 1;
                if (i % primes[j] == 0) break;
            }
        }
        for (int i = 2; i <= N - 10; i++) {
            if (!vis[i]) {
                s[i] = s[i - 1] + 1;
            } else {
                s[i] = s[i - 1];
            }
        }
    }

} A;

void solve() {
    int l, r;
    cin >> l >> r;

    cout << A.s[r] - A.s[l - 1] << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    A.init();
    while (Task--) {
        solve();
    }

    return 0;
}