#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];

    vector<int> stk;
    vector<i64> l(n + 1, 0), r(n + 1, n + 1);

    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && w[stk.back()] < w[i]) stk.pop_back();
        if (!stk.empty()) {
            l[i] = stk.back();
        }
        stk.push_back(i);
    }

    stk.clear();
    for (int i = n; i >= 1; i--) {
        while (!stk.empty() && w[stk.back()] < w[i]) stk.pop_back();
        if (!stk.empty()) {
            r[i] = stk.back();
        }
        stk.push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        i64 t1 = (i64)i * (n - i + 1);
        i64 t2 = (i64)l[i] * (n - r[i] + 1);
        cout << t1 - t2 << " \n"[i == n];
    }
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