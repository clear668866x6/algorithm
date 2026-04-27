#include <bits/stdc++.h>
using namespace std;

#define int long long

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;

    vector<vector<int>> sum(n + 1, vector<int>(30, 0));
    vector<vector<int>> sum2(n + 1, vector<int>(30, 0));
    vector<vector<int>> sum3(n + 1, vector<int>(30, 0));
    vector<vector<int>> mp(30);

    for (int i = 1; i <= n; i++) mp[s[i] - 'a'].push_back(i);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            sum[i][j] = sum[i - 1][j] + (j == s[i] - 'a');
        }
    }

    for (int i = 0; i < 30; i++) {
        for (int j = 1; j <= mp[i].size(); j++) {
            sum2[j][i] = sum2[j - 1][i] + mp[i][j - 1];
            sum3[j][i] = sum3[j - 1][i] + mp[i][j - 1] * j;
        }
    }

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        if (x == 1) {
            cout << r - l + 1 << '\n';
        } else if (x == 2) {
            i64 ans = 0;
            for (int j = 0; j < 30; j++) {
                int p = sum[r][j] - sum[l - 1][j];
                ans += p * (p - 1) / 2;
            }
            cout << ans << '\n';
        } else {
            i64 ans = 0;
            for (int j = 0; j < 30; j++) {
                int C = mp[j].size();
                auto it1 = lower_bound(mp[j].begin(), mp[j].end(), l);
                auto it2 = upper_bound(mp[j].begin(), mp[j].end(), r);
                it2--;
                int L = it1 - mp[j].begin() + 1, R = it2 - mp[j].begin() + 1;
                if (L >= 1 && R <= C && L <= R) {
                    int p1 = 2 * (sum3[R][j] - sum3[L - 1][j]);
                    int p2 = (L + R) * (sum2[R][j] - sum2[L - 1][j]);
                    int p3 = (R - L + 1) * (R - L) / 2;
                    ans += p1;
                    ans -= p2;
                    ans -= p3;
                }
            }
            cout << ans << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}