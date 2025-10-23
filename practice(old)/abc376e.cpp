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
    struct E{
        int a, b;
        bool operator<(const E& t)const{
            return a < t.a;
        }
    };
    V<E>a (n);
    FOR (i, 0, n - 1)cin >> a[i].a;
    FOR (i, 0, n - 1)cin >> a[i].b;
    sort (ALL (a));

    int ans = 1e18, sum = 0;

    multiset<int>s;

    FOR (i, 0, k - 1)sum += a[i].b, s.insert (a[i].b);

    ans = min (ans, a[k - 1].a * sum);

    FOR (i, k, n - 1){
        if (a[i].b < *(s.rbegin ())){
            int t = *s.rbegin ();
            sum -= t;
            sum += a[i].b;
            s.erase (s.find (t));
            s.insert (a[i].b);
        }
        ans = min (ans, sum * a[i].a);
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