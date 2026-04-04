#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct Prim {
    static constexpr int N = 2e6 + 10;
    int p[N], cnt;
    bool vis[N];

    void init() {
        int n = N - 10;
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) p[cnt++] = i;
            for (int j = 0; i * p[j] <= n; j++) {
                vis[i * p[j]] = 1;
                if (i % p[j] == 0) break;
            }
        }
    }

} A;

void solve() {
    int n;
    cin >> n;

    for (int i = 1, j = 0; i <= n; i++, j++) {
        cout << (i64)A.p[j] * A.p[j + 1] << ' ';
    }

    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    A.init();
    while (t--) {
        solve();
    }

    return 0;
}