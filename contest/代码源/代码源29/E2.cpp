#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

ll count0(ll X, int k) {
    if (X < 0) return 0;
    ll T = 1LL << (k + 1);
    ll blocks = (X + 1) / T;
    ll rem = (X + 1) % T;
    return blocks * (1LL << k) + min(rem, 1LL << k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<ll>> A(n, vector<ll>(4));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> A[i][j];
            A[i][j] %= mod;
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int k, c;
            ll v;
            cin >> k >> c >> v;
            A[k][c] = v % mod;
        } else {
            ll r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            ll ans = 0;
            for (int k = 0; k < n; k++) {
                ll r0 = count0(r2, k) - count0(r1 - 1, k);
                ll r1_cnt = (r2 - r1 + 1) - r0;
                ll c0 = count0(c2, k) - count0(c1 - 1, k);
                ll c1_cnt = (c2 - c1 + 1) - c0;

                ans = (ans + (__int128)A[k][0] * r0 % mod * c0) % mod;
                ans = (ans + (__int128)A[k][1] * r0 % mod * c1_cnt) % mod;
                ans = (ans + (__int128)A[k][2] * r1_cnt % mod * c0) % mod;
                ans = (ans + (__int128)A[k][3] * r1_cnt % mod * c1_cnt) % mod;
            }
            cout << ans << '\n';
        }
    }

    return 0;
}