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
    int n;
    cin >> n;

    V<int>w (n);
    for (auto& x : w)cin >> x;

    map<i128, int>mp1, mp2, mp3, mp4;

    int ans = 0;

    function<i128 (int, int)>get = [&] (int x, int y) {
        return (i128)x * (i128)(1e6) + (i128)y;
        };

    function<i128 (int, int, int)>get2 = [&] (int a, int b, int c) {
        return (i128)a * (i128)(1e12) + (i128)b * (i128)(1e6) + (i128)c;
        };

    FOR (i, 0, n - 3) {
        mp1[get (w[i + 1], w[i + 2])]++;
        mp2[get (w[i], w[i + 2])]++;
        mp3[get (w[i], w[i + 1])]++;
        mp4[get2 (w[i], w[i + 1], w[i + 2])]++;
    }

    for (auto [x, y] : mp1)ans += y * (y - 1) / 2;
    for (auto [x, y] : mp2)ans += y * (y - 1) / 2;
    for (auto [x, y] : mp3)ans += y * (y - 1) / 2;
    for (auto [x, y] : mp4)ans -= 3 * (y - 1) * y / 2;
    cout << ans << endl;

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