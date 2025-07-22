#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()

void solve () {
    int n, m;
    cin >> n;

    V<int>a (n), b (n);
    for (auto& x : a)cin >> x;
    for (auto& x : b)cin >> x;

    cin >> m;
    V<int>c (m);
    for (auto& x : c)cin >> x;

    map<int, int>mp, mp2;

    int tot = 0;

    FOR (i, 0, n - 1) {
        if (a[i] != b[i]) {
            tot++;
            mp[b[i]]++;
        }
        mp2[b[i]]++;
    }

    FOR (i, 0, m - 1) {
        if (mp[c[i]]) {
            mp[c[i]]--;
            tot--;
        }
    }

    if (mp2[c[m - 1]] <= 0 || tot > 0) {
        NO;
    } else {
        YES;
    }
}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> Task;

    while (Task--) {
        solve ();
    }

    return 0;
}