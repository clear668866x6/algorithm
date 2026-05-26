#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct BitTree {
    static constexpr int N = 2e5 + 10;
    int tr[N];

    void add(int x, int c) {
        for (int i = x; i < N; i += i & -i) tr[i] += c;
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= i & -i) ans += tr[i];
        return ans;
    }

} A;

void solve() {
    int n, l;
    cin >> n >> l;
    vector a(n + 1, vector(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    vector val(6, vector(10, 0));
    val[2][2] = val[2][3] = val[2][5] = val[2][6] = val[2][8] = 1;
    val[3][2] = val[3][3] = val[3][9] = 1;
    val[4][2] = val[4][3] = val[4][4] = val[4][5] = val[4][8] = val[4][9] = 1;
    val[5][8] = val[5][9] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + 4 <= n && j + 8 <= n) {
                int mx = -1, mn = l + 1;
                for (int x = i; x <= i + 4; x++) {
                    for (int y = j; y <= j + 8; y++) {
                        if (val[x - i + 1][y - j + 1]) {
                            mx = max(mx, a[x][y]);
                        } else {
                            mn = min(mn, a[x][y]);
                        }
                    }
                }
                if (mx + 1 <= mn) {
                    A.add(mx + 2, 1), A.add(mn + 2, -1);
                }
            }
        }
    }

    for (int i = 1; i <= l; i++) {
        if (A.query(i)) cout << i - 1 << '\n';
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