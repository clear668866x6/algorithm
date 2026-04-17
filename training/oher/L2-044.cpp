#include <bits/stdc++.h>
#include <sstream>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> f, m;
    vector<vector<int>> d(n + 1, vector<int>(n + 1, 1e9));

    for (int i = 1; i <= n; i++) d[i][i] = 0;

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == 'F')
            f.push_back(i);
        else
            m.push_back(i);

        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            string s;
            cin >> s;
            stringstream ss;
            ss << s;
            int v, dd;
            char cc;
            ss >> v >> cc >> dd;
            d[i][v] = min(d[i][v], dd);
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    vector<int> ans1, ans2;

    int mn = 1e9;

    for (int i = 0; i < m.size(); i++) {
        int mx = 0;
        for (int j = 0; j < f.size(); j++) {
            mx = max(mx, d[f[j]][m[i]]);
        }
        mn = min(mn, mx);
    }

    for (int i = 0; i < m.size(); i++) {
        int mx = 0;
        for (int j = 0; j < f.size(); j++) {
            mx = max(mx, d[f[j]][m[i]]);
        }
        if (mx == mn) {
            ans2.push_back(m[i]);
        }
    }

    mn = 1e9;
    for (int i = 0; i < f.size(); i++) {
        int mx = 0;
        for (int j = 0; j < m.size(); j++) {
            mx = max(mx, d[m[j]][f[i]]);
        }
        mn = min(mn, mx);
    }

    for (int i = 0; i < f.size(); i++) {
        int mx = 0;
        for (int j = 0; j < m.size(); j++) {
            mx = max(mx, d[m[j]][f[i]]);
        }
        if (mx == mn) {
            ans1.push_back(f[i]);
        }
    }

    for (int i = 0; i < ans1.size(); i++) cout << ans1[i] << " \n"[i == (int)ans1.size() - 1];
    for (int i = 0; i < ans2.size(); i++) cout << ans2[i] << " \n"[i == (int)ans2.size() - 1];
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