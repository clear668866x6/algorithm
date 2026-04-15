#include <bits/stdc++.h>
#include <sstream>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, q;
    cin >> n;
    cin.ignore();
    vector<string> p1(n + 1), p2(n + 1);
    map<string, vector<int>> mp;

    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        stringstream ss;
        ss << s;
        string p;
        while (ss >> p) {
            p1[i] += p[0];
        }
        p2[i] = s;
        mp[p1[i]].push_back(i);
    }

    cin >> q;
    cin.ignore();
    while (q--) {
        string s;
        getline(cin, s);
        stringstream ss;
        string p, show;
        ss << s;
        while (ss >> p) {
            show += p[0];
        }

        vector<string> ans;

        if (mp[show].empty()) {
            cout << s << '\n';
        } else {
            for (auto x : mp[show]) {
                ans.push_back(p2[x]);
            }

            sort(ans.begin(), ans.end(), [&](auto a, auto b) { return a < b; });

            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << "|\n"[i == (int)ans.size() - 1];
            }
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