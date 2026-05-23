#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;

    vector<int> mp(256, 0);
    for (int i = 1; i <= n; i++) mp[s[i]]++;

    vector<pair<int, char>> mp2;

    for (char c = 'a'; c <= 'z'; c++) {
        if (mp[c]) {
            mp2.push_back({mp[c], c});
        }
        if (mp[c] > (n + 1) / 2) {
            cout << "No\n";
            return;
        }
    }

    sort(mp2.rbegin(), mp2.rend());

    string ans(n + 1, ' ');

    char idx = 0;

    for (int i = 1; i <= n; i += 2) {
        while (!mp2[idx].first) idx++;
        ans[i] = mp2[idx].second;
        mp2[idx].first--;
    }

    for (int i = 2; i <= n; i += 2) {
        while (!mp2[idx].first) idx++;
        ans[i] = mp2[idx].second;
        mp2[idx].first--;
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; i++) cout << ans[i];
    cout << '\n';
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