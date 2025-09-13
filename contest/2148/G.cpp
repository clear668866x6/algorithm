#include <bits/stdc++.h>
#include <queue>
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

struct Prime {
    static constexpr int N = 2e5 + 10;
    int primes[N], cnt;
    int mn[N];
    bool vis[N];

    void init(int x) {
        FOR(i, 2, x) {
            if (!vis[i]) primes[cnt++] = i, mn[i] = i;
            for (int j = 0; i * primes[j] <= x; j++) {
                vis[i * primes[j]] = 1;
                mn[i * primes[j]] = primes[j];
                if (i % primes[j] == 0) break;
            }
        }
    }

} A;
const int N = 2e5 + 10;
int vis1[N], cnt[N];

void solve() {
    int n;
    cin >> n;

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    int cur = 0;

    priority_queue<PII> q;

    V<int> ans(n + 1, 0);

    FOR(i, 1, n) {
        int t = gcd(cur, w[i]);
        if (i == 1 || cur != t) {
            cur = t;
            memset(vis1, 0, sizeof vis1);
            FOR(j, 0, A.cnt - 1) {
                if (cur * A.primes[j] > n) break;
                vis1[A.primes[j]] = 1;
                cnt[A.primes[j]] = 0;
            }

            FOR(j, 1, i) {
                int b = w[j] / cur;
                set<int> s;
                int tmp = b;
                while (tmp > 1) {
                    int p0 = A.mn[tmp];
                    s.insert(p0);
                    while (tmp % p0 == 0) tmp /= p0;
                }
                for (auto p : s) {
                    if (p <= 2e5 && vis1[p]) {
                        cnt[p]++;
                    }
                }
            }

            while (sz(q)) q.pop();

            FOR(j, 0, A.cnt - 1) {
                if (cur * A.primes[j] > n) break;
                q.push({cnt[A.primes[j]], A.primes[j]});
            }
            if (!sz(q))
                ans[i] = 0;
            else {
                while (sz(q)) {
                    auto [x, y] = q.top();
                    if (x == cnt[y]) {
                        ans[i] = x;
                        break;
                    }
                    q.pop();
                }
            }
        } else {
            int b = w[i] / cur;
            set<int> s;
            int tmp = b;
            while (tmp > 1) {
                int p0 = A.mn[tmp];
                s.insert(p0);
                while (tmp % p0 == 0) tmp /= p0;
            }
            for (auto p : s) {
                if (p <= 2e5 && vis1[p]) {
                    cnt[p]++;
                    q.push({cnt[p], p});
                }
            }

            if (!sz(q))
                ans[i] = 0;
            else {
                while (sz(q)) {
                    auto [x, y] = q.top();
                    if (x == cnt[y]) {
                        ans[i] = x;
                        break;
                    }
                    q.pop();
                }
            }
        }
    }

    FOR(i, 1, n) cout << ans[i] << " \n"[i == n];
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    A.init(2e5);
    while (Task--) {
        solve();
    }

    return 0;
}
