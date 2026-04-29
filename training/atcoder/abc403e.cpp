#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct Tire {
    static constexpr int N = 5e5 + 10;
    int tr[N][30];
    int cnt[N], cnt2[N];
    int idx = 1;

    void insert(string s, int op, int &ans) {
        int p = 0;
        if (op == 2) ans++;

        if (op == 1) {
            int f = 0;
            for (auto x : s) {
                int u = x - 'a';
                if (!tr[p][u]) tr[p][u] = ++idx;
                p = tr[p][u];
                if (cnt[p]) f = 1;
            }
            if (f) return;
            cnt[p]++;
            if (cnt2[p]) {
                int tot = cnt2[p];
                ans -= tot;
                p = 0;
                for (auto x : s) {
                    int u = x - 'a';
                    p = tr[p][u];
                    cnt2[p] -= tot;
                }
            }

        } else {
            int f = 0;
            for (auto x : s) {
                int u = x - 'a';
                if (!tr[p][u]) tr[p][u] = ++idx;
                p = tr[p][u];
                cnt2[p]++;
                if (!f && cnt[p]) {
                    ans--;
                    f = 1;
                }
            }

            if (f) {
                p = 0;
                for (auto x : s) {
                    int u = x - 'a';
                    p = tr[p][u];
                    cnt2[p]--;
                }
            }
        }
    }

} A;

void solve() {
    int q;
    cin >> q;

    int ans = 0;
    while (q--) {
        int op;
        string s;
        cin >> op >> s;
        A.insert(s, op, ans);
        cout << ans << '\n';
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