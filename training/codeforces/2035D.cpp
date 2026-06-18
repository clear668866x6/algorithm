#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<i64> s1(n + 1, 0), s2(n + 1, 0);

    auto qmi = [&](i64 a, i64 b) {
        i64 ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    };

    for (int i = 1; i <= n; i++) {
        int t = a[i], cnt = 0;
        while (!(t & 1)) {
            cnt++;
            t /= 2;
        }
        b[i] = t;
        s1[i] = s1[i - 1] + t;
        s2[i] = s2[i - 1] + cnt;
    }

    vector<i64> f(n + 1, 0);

    vector<int> stk(1, 0);

    for (int i = 1; i <= n; i++) {
        while (stk.size() > 1) {
            int j = stk.back();

            if (s2[i] - s2[j] >= 30)
                stk.pop_back();
            else {
                i64 t = b[i] * qmi(2, s2[i] - s2[j]);
                if (t >= b[j]) {
                    stk.pop_back();
                } else {
                    break;
                }
            }
        }

        int j = stk.back();

        f[i] = (f[j] + (s1[i - 1] - s1[j]) % mod + qmi(2, s2[i - 1] - s2[j]) * a[i] % mod) % mod;
        stk.push_back(i);
    }

    for (int i = 1; i <= n; i++) cout << f[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}