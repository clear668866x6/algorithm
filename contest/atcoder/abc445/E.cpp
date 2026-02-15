#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
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

constexpr int mod = 998244353;

struct ST {
    static constexpr int N = 2e5 + 10;

    int f[N][22];

    void init(V<int> &w, int n) {
        FOR(j, 0, 20) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                if (!j)
                    f[i][j] = w[i];
                else {
                    f[i][j] = gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
                }
            }
        }
    }

    int query(int l, int r) {
        int len = __lg(r - l + 1);
        return gcd(f[l][len], f[r - (1 << len) + 1][len]);
    }
} A;

i128 qmi(i128 a, i128 b) {
    i128 ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    i128 t = a * b % mod;
    i128 p = gcd(a, b);
    return (i128)t * qmi(p, mod - 2) % mod;
}

void solve() {
    int n;
    cin >> n;

    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];
    V<int> pre(n + 1, 1), suf(n + 2, 1);
    FOR(i, 1, n) {
        pre[i] = lcm(pre[i - 1], w[i]);
    }

    FORD(i, 1, n) {
        suf[i] = lcm(suf[i + 1], w[i]);
    }

    FOR(i, 1, n) {
        cout << lcm(pre[i - 1], suf[i + 1]) % mod << ' ';
    }
    cout << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}
