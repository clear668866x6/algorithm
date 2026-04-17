#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, c;
    cin >> n >> c;

    priority_queue<pair<int, string>> q;
    map<string, int> mp;
    int idx = 0;
    map<int, set<int>> mp2;
    vector<string> s(n + 1);
    set<int> r;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> s[i] >> x;
        q.push({x, s[i]});
    }

    while (!q.empty()) {
        auto [n, sho] = q.top();
        q.pop();
        if (n >= c) {
            mp2[0].insert(++idx);
            r.insert(0);
            mp[sho]++;
            n -= c;
            if (n) {
                q.push({n, sho});
            }
        } else {
            int mn = idx + 10;
            int del = 0;
            for (auto it = r.lower_bound(n); it != r.end(); it++) {
                int x = *it;
                auto y = mp2[*it];
                if (mn > *y.begin()) {
                    mn = *y.begin();
                    del = x;
                }
            }

            if (mn == idx + 10) {
                mp2[c - n].insert(++idx);
                r.insert(c - n);
                mp[sho]++;
            } else {
                mp2[del].erase(mn);
                if (mp2[del].empty()) {
                    r.erase(del);
                }
                int t = del - n;
                mp2[t].insert(mn);
                r.insert(t);
                mp[sho]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << s[i] << " " << mp[s[i]] << '\n';
    }

    cout << idx;
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