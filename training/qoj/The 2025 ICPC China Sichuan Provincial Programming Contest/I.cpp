#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct Tire {
    static constexpr int N = 3e5 + 10;

    int tr[N][33];
    int idx = 1;
    int cnt[N * 33];

    void insert(string c) {
        int p = 0;
        for (int i = (int)c.size() - 1; i >= 0; i--) {
            int t = c[i] - 'a';
            if (!tr[p][t]) tr[p][t] = ++idx;
            p = tr[p][t];
            cnt[p]++;
        }
    }
} A;

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        A.insert(s);
    }

    i64 ans = 0;

    for (int i = 1; i <= A.idx; i++) {
        if (A.cnt[i]) {
            ans++;
        }
    }

    cout << ans << "\n";
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