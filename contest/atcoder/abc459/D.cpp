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

    vector<int> f(n + 1, 0);
    int m = (n + 1) / 2;
    f[0] = 1;
    vector<array<int, 2>> pat(m + 1);

    for (int c = 'a'; c <= 'z'; c++) {
        for (int j = m; j >= mp[c]; j--) {
            if (f[j - mp[c]] == 1 && f[j] == 0) {
                f[j] |= f[j - mp[c]];
                pat[j] = {j - mp[c], c};
            }
        }
    }

    auto get = [&](int m) {
        int t = m;
        vector<char> p;
        while (t != 0) {
            p.push_back(pat[t][1]);
            t = pat[t][0];
        }

        string ans(n + 1, ' ');
        int idx = 0;

        for (int i = 1; i <= n; i += 2) {
            while (!mp[p[idx]]) idx++;
            ans[i] = p[idx];
            mp[p[idx]]--;
        }

        int idx2 = 'a';
        for (int i = 2; i <= n; i += 2) {
            while (!mp[idx2]) idx2++;
            ans[i] = idx2;
            mp[idx2]--;
        }

        for (int i = 1; i <= n; i++) cout << ans[i];
        cout << '\n';
    };

    if (f[m]) {
        cout << "Yes\n";
        get(m);
    } else if ((n & 1) && f[m - 1]) {
        cout << "Yes\n";
        get(m - 1);
    } else {
        cout << "No\n";
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