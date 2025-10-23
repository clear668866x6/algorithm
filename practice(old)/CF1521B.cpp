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
//其实已经想到了放一个很大很大的质数，也就是1e9+7,但我不知道我为什么不继续想下去。
void solve() {
    int n;
    cin >> n;
    V<int>w(n);
    for (auto& x : w)cin >> x;

    bool f = false;

    FOR(i, 1, n - 1){
        if (__gcd(w[i], w[i - 1]) != 1){
            f = 1;
            break;
        }
    }
    if (!f){
        cout << 0 << endl;
        RE;
    }

    V<array<int, 4>>ans;

    int mx = 1e9 + 7;

    FOR2(i, 1, n - 1, 2){
        ans.pb({ i,i + 1,min(w[i - 1],w[i]),mx });
        w[i] = 1e9 + 7;
    }
    cout << ans.sz << endl;
    for (auto [a, b, c, d] : ans)cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
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