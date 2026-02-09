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

string p = "WGBPYO#";
double res;
string tttt;

void dfs(int u, string t) {
    if (u >= 6) {
        int c1 = 0;
        FOR(i, 0, 5) {
            if (t[i] == '#') c1++;
        }
        double ans = 0;
        map<char, int> mp;
        FOR(i, 0, 5) mp[t[i]]++;

        FOR(a, 0, 5) {
            FOR(b, 0, 5) {
                FOR(c, 0, 5) {
                    string tt;
                    tt += p[a];
                    tt += p[b];
                    tt += p[c];
                    map<char, int> mp2;
                    for (auto x : tt) mp2[x]++;

                    int tot = c1;
                    FOR(i, 0, 5) {
                        int t1 = mp2[p[i]], t2 = mp[p[i]];
                        if (t1 == 1) {
                            t1 = 2;
                        } else if (t1 == 2) {
                            t1 = 3;
                        } else if (t1 == 3) {
                            t1 = 10;
                        }
                        tot += (t1 * t2);
                    }
                    // cout << tot << endl;
                    ans += tot * (1.0 / 216.0);
                    // exit(0);
                }
            }
        }
        // cout << t << ' ' << ans << endl;
        if (res < ans) {
            res = ans;
            tttt = t;
        }

        RE;
    }

    FOR(i, 0, 6) {
        t += p[i];
        dfs(u + 1, t);
        t.pop_back();
    }
}

void solve() {
    dfs(0, "");
    cout << tttt << ' ' << res << endl;
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