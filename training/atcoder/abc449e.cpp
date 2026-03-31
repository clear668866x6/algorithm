#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct BIT {
    static constexpr int N = 5e5 + 10;

    i64 tr[N];

    void add(int x, int c) {
        for (int i = x; i < N; i += i & (-i)) tr[i] += c;
    }

    int find(int p) {
        int pos = 0;
        for (int k = 19; k >= 0; k--) {
            if (pos + (1 << k) < N && tr[pos + (1 << k)] < p) {
                pos += (1 << k);
                p -= tr[pos];
            }
        }
        return pos + 1;
    }

} A;

void solve() {
    int n, m, q;
    cin >> n >> m;
    vector<int> a(n + 1, 0), cnt(m + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;

    map<int, vector<int>> mp;

    int mx = 0;

    for (int i = 1; i <= m; i++) mx = max(mx, cnt[i]);

    for (int i = 1; i <= m; i++) {
        mp[cnt[i]].push_back(i);
    }

    cin >> q;
    vector<array<i64, 2>> ans(q);
    for (int i = 0; i < q; i++) {
        i64 x;
        cin >> x;
        ans[i] = {x, i + 1};
    }

    sort(ans.begin(), ans.end());

    map<i64, i64> mp2;
    i64 st = n + 1;
    i64 cur = 0;
    int idx = 0;
    i64 tot = 0;

    while (idx <= mx && mp[idx].empty()) {
        idx++;
    }

    for (auto x : mp[idx]) A.add(x, 1), tot++;

    for (int i = 0; i < q; i++) {
        auto [x, id] = ans[i];
        if (mp2[id]) continue;
        if (x <= n) {
            mp2[id] = a[x];
        } else {
            i64 del = x - st;
            if (cur + del < tot) {
                cur += del;
            } else {
                if (idx >= mx) {
                    cur = (cur + del) % tot;
                } else {
                    del -= (tot - cur);
                    idx++;
                    for (auto v : mp[idx]) {
                        tot++;
                        A.add(v, 1);
                    }
                    while (idx < mx && tot <= del) {
                        del -= tot;
                        idx++;
                        for (auto v : mp[idx]) {
                            tot++;
                            A.add(v, 1);
                        }
                    }
                    if (idx >= mx) {
                        cur = del % tot;
                    } else {
                        cur = del;
                    }
                }
            }

            mp2[id] = A.find(cur + 1);
            st = x;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << mp2[i + 1] << "\n";
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