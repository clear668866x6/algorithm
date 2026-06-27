#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    map<int, vector<array<int, 2>>> mp;
    map<int, int> mp2;

    for (int i = 1; i <= n; i++) {
        int a, d, b;
        cin >> a >> d >> b;
        mp[d].push_back({a, b});
        mp2[a]++;
    }

    for (int i = 1; i <= m; i++) {
        for (auto [a, b] : mp[i]) {
            if (mp2[a] - 1 == 0) {
                mp2.erase(a);
                mp2[b]++;
            } else {
                mp2[a]--;
                mp2[b]++;
            }
        }
        cout << mp2.size() << '\n';
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