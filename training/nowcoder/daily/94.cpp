#include <bits/stdc++.h>
#include <iomanip>
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

void solve() {
    int n, m;
    cin >> n >> m;
    string anser;
    cin >> anser;

    struct E {
        int score;
        string name;
        bool operator<(const E &t) const {
            if (score == t.score) return name < t.name;
            return score > t.score;
        }
    };

    V<E> c;

    FOR(i, 1, m) {
        string name, s;
        cin >> name >> s;
        int tot = 0;
        FOR(j, 0, n - 1) {
            if (anser[j] == s[j]) tot++;
        }
        c.pb({tot, name});
    }

    sort(ALL(c));

    int mx = c[0].score;

    FOR(i, 0, m - 1) {
        if (mx == c[i].score) {
            cout << c[i].name << endl;
            cout << fixed << setprecision(2) << (double)((1. * c[i].score) / n) * 100.0 << endl;
            break;
        }
    }
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