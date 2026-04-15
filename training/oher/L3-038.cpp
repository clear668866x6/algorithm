#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define int long long

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    vector<int> pos(n + 1, 0), pos1, pos0;
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pos[i] = i;
        if (s[i] == '1')
            pos1.push_back(i);
        else
            pos0.push_back(i);

        pre[i + 1] = pre[i] + (s[i] == '1');
    }

    int req = max((int)0, k - m);

    for (int i = 0; i < n; i++) {
        int L = 0;
        auto getd = [&](int x, int k, vector<int> &P) {
            int n = P.size();
            vector<int> pre(n + 1, 0);
            for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + P[i];
            if (!k) return (int)0;
            while (L + k < n && P[L] + P[L + k] <= 2 * x) L++;

            auto it = upper_bound(P.begin() + L, P.begin() + L + k, x);
            int idx = it - P.begin();
            int cntl = idx - L;
            int suml = pre[idx] - pre[L];
            int cntr = L + k - idx;
            int sumr = pre[L + k] - pre[idx];
            return (cntl * x - suml + sumr - cntr * x);
        };
        int t = getd(i, k, pos);
        auto getl = [&](int x, vector<int> &P) {
            if (!k) return (int)0;
            while (L + k < P.size() && P[L] + P[L + k] <= 2 * i) L++;
            return L;
        };
        int Lal = getl(i, pos);
        int c1 = pre[Lal + k] - pre[Lal];

        if (c1 >= req) {
            cout << t << " \n"[i == n - 1];
        } else {
            L = 0;
            int t1 = getd(i, req, pos1);
            L = 0;
            int t2 = getd(i, k - req, pos0);
            cout << (t1 + t2) << " \n"[i == n - 1];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}