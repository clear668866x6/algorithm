#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    int m = 2 * n;
    vector<int> w(m + 1, 0);

    for (int i = 1; i <= m; i++) cin >> w[i];

    int ans = 1, idx1 = 0, idx2 = 0;

    for (int i = 1; i <= m; i++) {
        if (!w[i] && !idx1) {
            idx1 = i;
        } else if (!w[i]) {
            idx2 = i;
        }
    }

    auto calc = [&](int idx) {
        int mex = 0;
        set<int> s;
        s.insert(0);
        int l = idx - 1, r = idx + 1;
        while (l >= 1 && r <= m) {
            if (w[l] == w[r]) {
                s.insert(w[l]);
                while (s.count(mex)) mex++;
                l--, r++;
            } else {
                break;
            }
        }
        while (s.count(mex)) mex++;
        ans = max(ans, mex);
    };

    calc(idx1), calc(idx2);
    int mex = 0;
    set<int> s;
    s.insert(0);
    bool f = false;
    int l = idx1, r = idx2;
    while (l <= r) {
        if (w[l] == w[r]) {
            s.insert(w[l]);
            while (s.count(mex)) mex++;
            l++, r--;
        } else {
            f = 1;
            mex = 1;
            s.clear();
            break;
        }
    }

    if (!f) {
        l = idx1, r = idx2;
        while (l <= r) {
            if (w[l] == w[r]) {
                s.insert(w[l]);
                while (s.count(mex)) mex++;
                l--, r++;
            } else {
                break;
            }
        }
    }

    while (s.count(mex)) mex++;
    ans = max(ans, mex);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}