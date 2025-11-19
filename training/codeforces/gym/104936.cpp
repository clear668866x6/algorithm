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

struct Tire {
    static constexpr int N = 3100000;
    vector<int32_t> tr[2];
    vector<int32_t> cnt;
    int32_t idx;

    Tire() {
        idx = 1;
        tr[0].resize(N, 0);
        tr[1].resize(N, 0);
        cnt.resize(N, 0);
    }

    inline void insert(int x) {
        int32_t p = 0;
        FORD(i, 0, 29) {
            int u = x >> i & 1;
            cnt[p]++;
            if (!tr[u][p]) tr[u][p] = idx++;
            p = tr[u][p];
        }
        cnt[p]++;
    }

    inline void remove(int x) {
        int32_t p = 0;
        FORD(i, 0, 29) {
            int u = x >> i & 1;
            cnt[p]--;
            p = tr[u][p];
        }
        cnt[p]--;
    }

    inline int findmx(int x) {
        int32_t p = 0;
        int ans = 0;
        FORD(i, 0, 29) {
            ans *= 2;
            int u = x >> i & 1;
            if (tr[u ^ 1][p] && cnt[tr[u ^ 1][p]]) {
                p = tr[u ^ 1][p];
                ans++;
            } else {
                p = tr[u][p];
            }
        }
        return ans;
    }

    inline int findmn(int x) {
        int32_t p = 0;
        int ans = 0;
        FORD(i, 0, 29) {
            ans *= 2;
            int u = x >> i & 1;
            if (tr[u][p] && cnt[tr[u][p]]) {
                p = tr[u][p];
            } else {
                p = tr[u ^ 1][p];
                ans++;
            }
        }
        return ans;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    auto calc = [&](int k) {
        Tire A;
        int r = 1, ans = 0;
        FOR(l, 1, n) {
            if (l == r) A.insert(w[l]), r++;
            while (r <= n && A.findmn(w[r]) >= k) {
                A.insert(w[r]);
                r++;
            }
            ans += r - l;
            A.remove(w[l]);
        }
        return ans;
    };

    cout << calc(k) - calc(k + 1);
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