#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    unordered_map<string, char> mp;
    for (int i = 1; i <= n; i++) {
        string s;
        char c;
        cin >> s >> c;
        mp[s] = c;
    }

    int q;
    cin >> q;
    vector<int> ans;
    for (int idx = 1; idx <= n; idx++) {
        int len;
        cin >> len;
        int cnt = 0;
        for (int i = 1; i <= len; i++) {
            string x;
            cin >> x;
            if (mp[x] == 'i') {
                cnt++;
            }
        }
        if (cnt == len) {
            ans.push_back(idx);
        }
    }

    if (ans.empty()) {
        cout << "None";
    } else {
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i == (int)ans.size() - 1];
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