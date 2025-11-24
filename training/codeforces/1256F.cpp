#include <bits/stdc++.h>
using namespace std;

// #define int int64_t
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

struct FenWikTree {
    static constexpr int N = 100 + 10;
    V<int> tr;

    FenWikTree() {
        tr.resize(N, 0);
    }

    void add(int x, int c) {
        for (int i = x; i < N; i += lowbit(i)) tr[i] += c;
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) ans += tr[i];
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = ' ' + s, t = ' ' + t;

    map<char, int> mp1, mp2;

    FOR(i, 1, n) mp1[s[i]]++, mp2[t[i]]++;

    if (mp1 != mp2) {
        NO;
        RE;
    }

    for (auto [x, y] : mp1) {
        if (y > 1) {
            YES;
            RE;
        }
    }

    for (auto [x, y] : mp2) {
        if (y > 1) {
            YES;
            RE;
        }
    }

    V<int> w1(n + 1, 0), w2(n + 1, 0);

    FOR(i, 1, n) {
        w1[i] = s[i] - 'a' + 3;
        w2[i] = t[i] - 'a' + 3;
    }

    int t1 = 0, t2 = 0;

    FenWikTree A, B;

    FOR(i, 1, n) {
        t1 += i - 1 - A.query(w1[i]);
        A.add(w1[i], 1);
        t2 += i - 1 - B.query(w2[i]);
        B.add(w2[i], 1);
    }

    if (!((t1 ^ t2) & 1)) {
        YES;
    } else {
        NO;
    }
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}
