#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n + 1, 0);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++;
    for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];

    if (mp[a[1]] == n) {
        cout << a[1] << '\n';
        return;
    }
    struct E {
        int val, idx;
        bool operator<(const E &t) const {
            if (val == t.val) return idx > t.idx;
            return val < t.val;
        }
    };
    priority_queue<E> q;

    vector<int> b(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i + n - 1]) {
            for (int j = i; j <= i + n - 1; j++) {
                b[j - i + 1] = a[j];
            }
            break;
        }
    }

    for (int i = 1; i <= n; i++) q.push({b[i], i});

    vector<int> vis(n + 1, 0);

    i64 ans = 0;

    while (!q.empty()) {
        auto [val, idx] = q.top();
        q.pop();

        if (vis[idx]) continue;
        ans += val;
        int j = idx;
        vis[idx] = 1;
        auto get = [&](int p) {
            if (p > n) {
                p = 1;
            }
            return p;
        };
        while (!vis[get(j + 1)] && b[get(j + 1)] <= b[j]) {
            j = get(j + 1);
            vis[j] = 1;
        }
    }

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