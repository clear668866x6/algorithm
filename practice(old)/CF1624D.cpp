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
    int n, k;
    string s;
    cin >> n >> k >> s;

    s = ' ' + s;
    map<char, int> mp;
    FOR(i, 1, n) mp[s[i]]++;

    int c = 0;

    for (auto [x, y] : mp) {
        if (y & 1) c++;
    }

    int l = 0, r = (n / k + 1);

    auto check = [&](int x) {
        int len = k * x;
        if (x & 1) {
            int del = n - c;
            if (del >= (len - k)) return 1;
            return 0;
        } else {
            int del = n - c;
            if (del >= len) return 1;
            return 0;
        }
    };

    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    cout << l << endl;
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
