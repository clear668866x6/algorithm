#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

struct Comb {
    static constexpr int N = 2e5 + 10;

    i64 fac[N], infac[N];

    i64 qmi(i64 a, i64 b) {
        i64 ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    }

    void init() {
        int n = N - 10;

        fac[0] = 1;
        for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
        infac[n] = qmi(fac[n], mod - 2);

        for (int i = n - 1; i >= 0; i--) infac[i] = infac[i + 1] * (i + 1) % mod;
    }

    i64 C(i64 a, i64 b) {
        return fac[a] * infac[b] % mod * infac[a - b] % mod;
    }

} A;

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    s = ' ' + s;

    vector<int> p(n + 1, 0), siz(n + 1, 0);
    for (int i = 1; i <= n; i++) p[i] = i, siz[i] = 1;

    A.init();

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    vector<vector<int>> mp(n + 1, vector<int>(30, 0));

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            siz[b] += siz[a];
        }
    }
    map<int, int> mp2;

    for (int i = 1; i <= n; i++) {
        mp[find(i)][s[i] - 'a']++;
        mp2[find(i)] = 1;
    }

    i64 ans = 1;
    bool f = false;

    for (auto [x, y] : mp2) {
        i64 cnt = 1;
        i64 tot = siz[x];
        for (int j = 0; j < 30; j++) {
            if (mp[x][j]) {
                if (mp[x][j] >= 2) f = 1;
                cnt = cnt * A.C(tot, mp[x][j]) % mod;
                tot -= mp[x][j];
            }
        }
        ans = ans * cnt % mod;
    }

    if (!f) ans = ans * A.qmi(2, mod - 2) % mod;

    cout << ans;
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