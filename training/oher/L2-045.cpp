#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a, b, c(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    a.push_back(c[1]);
    int cnt = 0, mx = 0;

    for (int i = 2; i <= n; i++) {
        int t = c[i];
        if (!a.empty() && a.back() > t) {
            a.push_back(t);
        } else if (!a.empty() && a.back() <= t) {
            if (b.empty()) {
                b.push_back(t);
            } else if (!b.empty() && b.back() < t) {
                b.push_back(t);
            } else {
                mx = max(mx, (int)a.size());
                while (!a.empty()) a.pop_back();
                while (!b.empty() && b.back() >= t) {
                    a.push_back(b.back());
                    b.pop_back();
                }
                cnt++;
                a.push_back(t);
            }
        }
    }

    if (!a.empty()) cnt++, mx = max(mx, (int)a.size());
    if (!b.empty()) cnt++, mx = max(mx, (int)b.size());

    cout << cnt << ' ' << mx;
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