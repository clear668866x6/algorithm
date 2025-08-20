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

void solve() {
    string s;
    cin >> s;

    map<char, int> mp, mp2;

    for (auto x : s) {
        mp[x]++;
    }

    FOR(i, 0, sz(s) - 1) {
        mp2[s[i]] = i + 1;
    }

    FOR(i, 'a', 'a' + sz(s) - 1) {
        if (mp[i] > 1 || !mp[i]) {
            NO;
            RE;
        }
    }

    if (sz(s) == 1) {
        YES;
        RE;
    }

    bool isleft = false;

    if (mp2['b'] - mp2['a'] == -1) {
        isleft = 1;
    } else if (mp2['b'] - mp2['a'] == 1) {
        isleft = 0;
    } else {
        NO;
        RE;
    }

    FOR(i, 'c', 'a' + sz(s) - 1) {
        int del = mp2[i] - mp2[i - 1];
        if (!isleft) {
            if (del == 1) {
                isleft = 0;
            } else if (del == -(i - 'a')) {
                isleft = 1;
            } else {
                NO;
                RE;
            }
        } else {
            if (del == -1) {
                isleft = 1;
            } else if (del == (i - 'a')) {
                isleft = 0;
            } else {
                NO;
                RE;
            }
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
