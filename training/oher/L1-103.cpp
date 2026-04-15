#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int a, b;
    cin >> a >> b;

    vector<int> ans;
    int mx = 0;

    for (int i = a; i <= b; i++) {
        string s = to_string(i);
        int cnt = 0;
        while (s.size() != 1) {
            cnt++;
            int p = 1;
            for (auto x : s) p *= (x - '0');
            s = to_string(p);
        }
        mx = max(mx, cnt);
    }

    cout << mx << "\n";

    for (int i = a; i <= b; i++) {
        string s = to_string(i);
        int cnt = 0;
        while (s.size() != 1) {
            cnt++;
            int p = 1;
            for (auto x : s) p *= (x - '0');
            s = to_string(p);
        }
        if (mx == cnt) {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == (int)ans.size() - 1];
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