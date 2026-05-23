#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> seg(n + 1);
    vector<int> L, hv(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        seg[l].push_back(r);
        L.push_back(l);
        hv[l] = 1;
    }
    sort(L.begin(), L.end());
    for (int i = 1; i <= n; i++) sort(seg[i].begin(), seg[i].end());

    vector<int> mn(n + 2, 1e9), mn2(n + 2, 1e9);

    for (int i = n; i >= 1; i--) {
        if (hv[i]) {
            int t = seg[i][0], t2 = 1e9;
            if (seg[i].size() >= 2) {
                t2 = seg[i][1];
            }
            cout << i << ' ' << t << ' ' << t2 << endl;
            mn[i] = t;
            mn2[i] = t2;
        }
        mn[i] = min(mn[i], mn[i + 1]);
        mn2[i] = min(mn2[i], mn2[i + 1]);
    }

    int q;
    cin >> q;

    while (q--) {
        int s, t;
        cin >> s >> t;

        auto it = lower_bound(L.begin(), L.end(), s);
        if (it == L.end()) {
            cout << "No\n";
        } else {
            int val = *it;
            int val2 = mn[val];
            int val3 = mn2[val];
            cout << s << ' ' << t << ' ' << val << ' ' << val3 << endl;
            if (t >= val3) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
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