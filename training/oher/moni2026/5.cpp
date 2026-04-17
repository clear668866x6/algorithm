#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int y, n;
    cin >> y >> n;

    for (int i = y, cnt = 0; i <= 5000; i++, cnt++) {
        string s = to_string(i);
        reverse(s.begin(), s.end());
        while (s.size() < 4) s.push_back('0');
        set<int> sp;
        for (auto x : s) {
            sp.insert(x);
        }
        reverse(s.begin(), s.end());
        if (sp.size() == n) {
            cout << cnt << ' ' << s;
            return;
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