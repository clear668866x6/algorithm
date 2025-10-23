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
    int n, k;
    cin >> n >> k;
    V<int>w (n);
    for (auto& x : w)cin >> x;

    int s2 = 0, s5 = 0, t2 = 0, t5 = 0;

    int l = 0, r = 0, ans = 0;

    function<int (int)>calc_c2 = [&] (int x){
        int c1 = 0;
        while (x % 2 == 0)c1++, x /= 2;
        return c1;
        };

    function<int (int)>calc_c5 = [&] (int x){
        int c1 = 0;
        while (x % 5 == 0)c1++, x /= 5;
        return c1;
        };

    FOR (i, 0, n - 1){
        s2 += calc_c2 (w[i]);
        t2 += calc_c2 (w[i]);
        s5 += calc_c5 (w[i]);
        t5 += calc_c5 (w[i]);
        while (l <= i && min (s2, s5) > k){
            s2 -= calc_c2 (w[l]);
            s5 -= calc_c5 (w[l++]);
        }

        while (r <= i && min (t2, t5) >= k){
            t2 -= calc_c2 (w[r]);
            t5 -= calc_c5 (w[r++]);
        }
        ans += (r - l);
    }
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