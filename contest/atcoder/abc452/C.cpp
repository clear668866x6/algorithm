#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n;

    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], b[i]--;

    cin >> m;
    vector<string> s(m + 1);
    vector<vector<vector<int>>> mp(20, vector<vector<int>>(20, vector<int>(256, 0)));
    for (int i = 1; i <= m; i++) {
        cin >> s[i];
        int t = s[i].size();
        for (int j = 1; j <= n; j++) {
            if (a[j] == t) {
                mp[t][b[j]][s[i][b[j]]]++;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        bool f = false;
        if (s[i].size() != n) {
            cout << "No\n";
        } else {
            for (int j = 1; j <= n; j++) {
                if (!mp[a[j]][b[j]][s[i][j - 1]]) {
                    cout << "No\n";
                    f = 1;
                    break;
                }
            }
            if (!f) {
                cout << "Yes\n";
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