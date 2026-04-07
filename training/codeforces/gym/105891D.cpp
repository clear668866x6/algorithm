#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    double v;
    cin >> n >> v;

    vector<pair<char, double>> w(n + 1);
    vector<double> jia, cheng;

    for (int i = 1; i <= n; i++) {
        cin >> w[i].first >> w[i].second;
        if (w[i].first == '+') {
            jia.push_back(w[i].second);
        } else {
            cheng.push_back(w[i].second);
        }
    }

    sort(jia.rbegin(), jia.rend());
    sort(cheng.rbegin(), cheng.rend());

    vector<int> vis(n + 1, 0);

    int sjia = jia.size(), scheng = cheng.size();

    double ans = 0;

    auto dfs = [&](auto &&dfs, int u, int l, int r, double cur, double tot) {
        if (l > sjia || r > scheng) return;
        if (u > n) {
            ans = max(ans, tot);
            return;
        }

        if (l < sjia) {
            dfs(dfs, u + 1, l + 1, r, cur + jia[l], tot + cur + jia[l]);
        }
        if (r < scheng) {
            dfs(dfs, u + 1, l, r + 1, cur * cheng[r], tot + cur * cheng[r]);
        }
    };

    dfs(dfs, 1, 0, 0, v, 0);

    cout << fixed << setprecision(12) << ans / n;
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