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

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

struct Init {
    static constexpr int N = 110;
    int msk[N], base[N];

    void init() {
        FOR(x, 1, 100) {
            int state = 0;
            int v = x;
            FOR(j, 0, 24) {
                int p = prime[j], c = 0;
                while (v % p == 0) {
                    v /= p;
                    c ^= 1;
                }
                if (c) state |= (1ll << j);
            }
            msk[x] = state;
        }
    }

} A;

void solve() {
    int n, q;
    cin >> n >> q;
    V<int> w(n + 1, 0);
    V<V<int>> s(n + 1, V<int>(101, 0));
    FOR(i, 1, n) cin >> w[i];

    FOR(i, 1, n) {
        FOR(j, 1, 100) {
            s[i][j] = s[i - 1][j] + (j == w[i]);
        }
    }

    set<int> st;
    FOR(i, 1, 20) {
        st.insert(i * i);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (r - l + 1 >= 26) {
            Yes;
            continue;
        }
        if (l == r) {
            if (st.count(w[l])) {
                Yes;
            } else {
                No;
            }
        } else {
            bool f = false;
            FOR(k, 1, 100) {
                int p = s[r][k] - s[l - 1][k];
                if (p == 1 && st.count(k)) {
                    Yes;
                    f = 1;
                    break;
                }
                if (p >= 2) {
                    Yes;
                    f = 1;
                    break;
                }
            }
            if (f) continue;
            V<int> base(30, 0);

            auto check = [&](int x) {
                FORD(i, 0, 24) {
                    if (x >> i & 1) {
                        if (!base[i]) {
                            base[i] = x;
                            return 1;
                        }
                        x ^= base[i];
                    }
                }
                return 0;
            };

            FOR(i, l, r) {
                if (!check(A.msk[w[i]])) {
                    Yes;
                    f = 1;
                    break;
                }
            }

            if (!f) {
                No;
            }
        }
    }
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    A.init();
    while (Task--) {
        solve();
    }

    return 0;
}