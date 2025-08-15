#include <bits/stdc++.h>
#include <functional>
using namespace std;

#ifndef ONLINE_JUDGE
    #include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i <= (int)(b); i -= (int)(c))
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
    int n, k;
    string a, b;
    cin >> n >> k >> a >> b;

    a = ' ' + a, b = ' ' + b;

    V<int> p(n + 1, 0);
    iota(ALL(p), 0LL);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    FOR(i, 1, n) {
        if (i - k >= 1) {
            int a = i - k, b = i;
            a = find(a), b = find(b);
            if (a != b) {
                p[a] = b;
            }
        }
        if (i - k - 1 >= 1) {
            int a = i - k - 1, b = i;
            a = find(a), b = find(b);
            if (a != b) {
                p[a] = b;
            }
        }
        if (i + k <= n) {
            int a = i, b = i + k;

            a = find(a), b = find(b);
            if (a != b) {
                p[a] = b;
            }
        }
        if (i + k + 1 <= n) {
            int a = i, b = i + k;

            a = find(a), b = find(b);
            if (a != b) {
                p[a] = b;
            }
        }
    }

    map<char, V<int>> mp, mp2;

    FOR(i, 1, n) {
        if (a[i] == b[i]) continue;
        mp[a[i]].eb(i);
        mp2[b[i]].eb(i);
    }

    FOR(c, 'a', 'z') {
        if (sz(mp[c]) != sz(mp2[c])) {
            NO;
            RE;
        }
        map<int, int> mp3;
        for (auto &x : mp[c]) x = find(x), mp3[x]++;
        for (auto x : mp2[c]) {
            x = find(x);
            if (!mp3[x]) {
                NO;
                RE;
            }
            mp3[x]--;
        }
    }
    YES;
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
