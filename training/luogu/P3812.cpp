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

struct Linear_basis {
    static constexpr int N = 55;
    int num[N];

    bool insert(int x) {
        FORD(i, 0, 49) {
            if (x >> i & 1) {
                if (!num[i]) {
                    num[i] = x;
                    return true;
                }
                x ^= num[i];
            }
        }
        return false;
    }

    int querymin(int x) {
        FORD(i, 0, 49) {
            x = min(x, x ^ num[i]);
        }
        return x;
    }

    int querymax(int x) {
        FORD(i, 0, 49) {
            x = max(x, x ^ num[i]);
        }
        return x;
    }

} A;

void solve() {
    int n;
    cin >> n;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    FOR(i, 1, n) {
        A.insert(w[i]);
    }

    cout << (A.querymax(0));
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