#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, k;
    cin >> n;

    vector<string> mp(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> mp[i];
    }

    cin >> k;

    string s;
    cin.ignore();
    getline(cin, s);
    string p;
    stringstream ss;
    ss << s;
    int cnt = 0;
    while (ss >> p) {
        for (int i = 1; i <= n; i++) {
            auto it = s.find(mp[i]);
            while ((it = s.find(mp[i])) != -1) {
                int len = mp[i].size();
                s.replace(it, len, "$%$");
                cnt++;
            }
        }
    }

    if (cnt >= k) {
        cout << cnt << '\n';
        cout << "He Xie Ni Quan Jia!";
        return;
    }

    auto it = s.find("$%$");
    while ((it = s.find("$%$")) != -1) {
        s.replace(it, 3, "<censored>");
        cnt++;
    }

    cout << s;
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