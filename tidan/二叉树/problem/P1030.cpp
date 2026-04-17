#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string a, b;
    cin >> a >> b;

    auto dfs = [&](auto &&dfs, string a, string b) {
        if (a.empty()) return;
        char p = b.back();
        cout << char(p);
        int t = a.find(p);
        dfs(dfs, a.substr(0, t), b.substr(0, t));
        dfs(dfs, a.substr(t + 1), b.substr(t, b.size() - t - 1));
    };

    dfs(dfs, a, b);
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