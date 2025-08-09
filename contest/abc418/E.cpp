#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) (int)(x).size()

int gcd(int x, int y) {
    x = abs(x), y = abs(y);
    if (!x && !y)
        return 1;
    if (!x)
        return y;
    if (!y)
        return x;
    while (y != 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

struct pair_hash {
    template <class T1, class T2> std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

void solve() {
    int n;
    cin >> n;

    V<array<int, 2>> w(n);

    for (auto& [a, b] : w)
        cin >> a >> b;

    unordered_map<PII, V<PII>, pair_hash> mp;
    unordered_map<PII, int, pair_hash> mp2;

    FOR(i, 0, n - 1) {
        FOR(j, i + 1, n - 1) {
            int dx = w[j][0] - w[i][0];
            int dy = w[j][1] - w[i][1];

            if (!dx && !dy)
                continue;

            PII k;

            if (!dx) {
                if (dy < 0)
                    dy = -dy;
                k = {0, 1};
            } else {
                if (dx < 0) {
                    dx = -dx, dy = -dy;
                }
                int t = gcd(dx, abs(dy));
                dx /= t, dy /= t;
                k = {dx, dy};
            }
            mp[k].eb(i, j);
            mp2[{w[j][0] + w[i][0], w[j][1] + w[i][1]}]++;
        }
    }

    int p = 0;

    for (auto [a, b] : mp) {
        int tot = (sz(b) - 1) * (sz(b)) / 2;

        unordered_map<int, int> mp3;

        for (auto [x, y] : b) {
            mp3[x]++;
            mp3[y]++;
        }

        int t = 0;

        for (auto [x, y] : mp3) {
            t += y * (y - 1) / 2;
        }
        p += tot - t;
    }

    int cnt = 0;

    for (auto [x, y] : mp2) {
        cnt += y * (y - 1) / 2;
    }

    cout << (p - cnt);
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}