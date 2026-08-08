#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct BITTree {
    static constexpr int N = 5e5 + 10;

    i64 tr[N];

    void add(int x, int c) {
        for (int i = x; i < N; i += i & -i) tr[i] = tr[i] + c;
    }

    i64 query(int x) {
        i64 ans = 0;
        for (int i = x; i; i -= i & -i) ans += tr[i];
        return ans;
    }

} A;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> cnt(64, 0);

    set<int> s;

    while (q--) {
        i64 op, x;
        cin >> op;
        i64 ans = 0;
        if (op == 1) {
            cin >> x;
            i64 t1 = A.query(x);
            for (int k = 0; k < 60; k++) {
                if (t1 >> k & 1) {
                    cnt[k]--;
                }
            }
            A.add(x, 1), A.add(x + 1, -1);
            t1 = A.query(x);
            for (int k = 0; k < 60; k++) {
                if (t1 >> k & 1) {
                    cnt[k]++;
                }
            }
            s.insert(x);
        } else {

            vector<int> c;
            for (auto x : s) {
                i64 v = A.query(x);

                for (int k = 0; k < 60; k++) {
                    if (v >> k & 1) {
                        cnt[k]--;
                    }
                }
                A.add(x, -1), A.add(x + 1, 1);
                v = A.query(x);

                for (int k = 0; k < 60; k++) {
                    if (v >> k & 1) {
                        cnt[k]++;
                    }
                }
                if (!v) {
                    c.push_back(x);
                }
            }

            for (auto x : c) s.erase(x);
        }

        for (int k = 0; k < 60; k++) {
            if (cnt[k] & 1) {
                ans |= (1ll << k);
            }
        }

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