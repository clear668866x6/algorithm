#include <bits/stdc++.h>
using namespace std;

#define int int64_t

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
#define fi first
#define se second

void solve() {
    int n;
    cin >> n;

    V<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);

    map<int, int> mp, mp2, mp3;

    FOR(i, 1, n) cin >> a[i], mp[a[i]]++;

    cout << "- 0" << endl;

    while (1) {
        FOR(i, 1, n) cin >> b[i], mp2[b[i]]++;

        if (mp == mp2) {
            cout << "- 0" << endl;
            FOR(i, 1, n) cin >> c[i], mp3[c[i]]++;

            FOR(i, 1, n) mp3[a[i]]--;
            int pos = 0;
            FOR(i, 1, n) {
                if (mp3[c[i]] > 0) {
                    pos = c[i];
                    break;
                }
            }

            V<int> p;

            FOR(i, 1, n) {
                if (c[i] != pos) {
                    p.push_back(i);
                }
            }
            cout << "- " << (int)p.size() << ' ';
            for (auto x : p)
                cout << x << ' ';
            cout << endl;
            mp3.clear();
            FOR(i, 1, n) {
                if (c[i] == pos)
                    mp3[c[i]]++;
            }
            n -= (int)p.size();
            V<int> d(n + 1, 0);
            map<int, int> mp4;
            FOR(i, 1, n) cin >> d[i], mp4[d[i]]++;

            if (mp4[pos] == mp3[pos]) {
                cout << "- 0" << endl;
                V<int> e(n + 1, 0);
                FOR(i, 1, n) cin >> e[i];
                FOR(i, 1, n) {
                    if (e[i] != pos) {
                        cout << "! " << i << endl;
                        RE;
                    }
                }
            } else {
                FOR(i, 1, n) {
                    if (d[i] != pos) {
                        cout << "! " << i << endl;
                        RE;
                    }
                }
            }

        } else {
            FOR(i, 1, n) mp2[a[i]]--;
            int pos = 0;
            FOR(i, 1, n) {
                if (mp2[b[i]] > 0) {
                    pos = b[i];
                    break;
                }
            }

            V<int> p;

            FOR(i, 1, n) {
                if (b[i] != pos) {
                    p.push_back(i);
                }
            }
            cout << "- " << (int)p.size() << ' ';
            for (auto x : p)
                cout << x << ' ';
            cout << endl;
            mp2.clear();
            FOR(i, 1, n) mp2[b[i]]++;

            n -= (int)p.size();
            V<int> d(n + 1, 0);

            FOR(i, 1, n) cin >> d[i], mp3[d[i]]++;

            if (mp2[pos] == mp3[pos]) {
                cout << "- 0" << endl;
                V<int> e(n + 1, 0);
                FOR(i, 1, n) cin >> e[i];
                FOR(i, 1, n) {
                    if (e[i] != pos) {
                        cout << "! " << i << endl;
                        RE;
                    }
                }
            } else {
                FOR(i, 1, n) {
                    if (d[i] != pos) {
                        cout << "! " << i << endl;
                        RE;
                    }
                }
            }
        }
    }
}

signed main() {
    int Task = 1;

    cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}