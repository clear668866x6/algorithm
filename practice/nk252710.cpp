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

    i128 t1 = 1, t2 = 1;

    function<int (i128)>calc = [&] (i128 x)->int{
        if (x == 0)return 1;
        int ans = 0;
        while (x > 0 && x % 10 == 0)ans++, x /= 10;
        return ans;
        };

    int ans = 0;
    int l = 0, r = 0;
    FOR (i, 0, n - 1){
        t1 *= w[i];
        t2 *= w[i];
        while (l <= i && calc (t1) > k){
            t1 /= w[l++];
        }
        while (r <= i && calc (t2) >= k){
            t2 /= w[r++];
        }
        ans += r - l;
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