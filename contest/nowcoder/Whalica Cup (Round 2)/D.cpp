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
    static constexpr int N = 2e5 + 10;
    int tr[N][30], cnt[N], idx;

    void insert(string s) {
        int p = 0;
        for (auto x : s) {
            int t = x - 'a';
            if (!tr[p][t]) tr[p][t] = ++idx;
            p = tr[p][t];
            cnt[p]++;
        }
    }

    int query(string s) {
        int p = 0;
        int ans = 0;
        for (auto x : s) {
            int t = x - 'a';
            if (!tr[p][t]) return ans;
            p = tr[p][t];
            ans += cnt[p];
        }
        return ans;
    }

} A;

void solve() {
    int n, q;
    cin >> n >> q;
    FOR(i, 1, n) {
        string s;
        cin >> s;
        A.insert(s);
    }

    int cnt = 0;

    string p = "wcilah";
    map<char, int> mp;
    FOR(i, 0, 5) mp[p[i]] = i;

    while (q--) {
        int op;
        string s;
        cin >> op;
        if (op == 1) {
            cin >> s;
            for (auto &x : s) {
                int t = mp[x];
                t += cnt;
                t %= 6;
                x = p[t];
            }
            cout << A.query(s) << endl;
        } else {
            cnt++;
            cnt %= 6;
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