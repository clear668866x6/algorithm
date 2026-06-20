#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    set<int> s;
    map<int, int> mp2;

    for (int i = 0; i < n; i++) {
        int h, l;
        cin >> h >> l;
        s.insert(l);
        mp2[l] = max(mp2[l], h);
    }

    int q;
    cin >> q;
    vector<int> b(q + 1, 0), c;
    for (int i = 1; i <= q; i++) cin >> b[i], c.push_back(b[i]);
    map<int, int> mp;

    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    int mx = 0;

    for (int i = (int)c.size() - 1; i >= 0; i--) {
        vector<int> d;
        for (auto it = s.upper_bound(c[i]); it != s.end(); it++) {
            d.push_back(*it);
            mx = max(mx, mp2[*it]);
        }

        for (auto x : d) {
            s.erase(s.find(x));
        }

        mp[c[i]] = mx;
    }

    for (int i = 1; i <= q; i++) {
        cout << mp[b[i]] << '\n';
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