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

    V<V<int>>cnt (n + 1, V<int> (5, 0));

    struct E{
        int x, y;
        bool operator<(const E& t)const{
            return 2 * x - y > 2 * t.x - t.y;
        }
    };
    V<E>a (n + 1), b;

    FOR (i, 1, n){
        string s;
        cin >> s;
        int mx = 0;
        for (auto& x : s){
            cnt[i][x - 'a']++;
            mx = max (mx, cnt[i][x - 'a']);
        }
        a[i] = { mx,(int)s.sz };
    }

    int ans = 0;

    FOR (c, 'a', 'e'){
        int ct = 0;
        b = a;
        FOR (i, 1, n){
            b[i].x = cnt[i][c - 'a'];
        }
        sort (b.begin () + 1, b.end ());

        if (b[1].x * 2 - b[1].y <= 0){
            continue;
        }

        int mx = b[1].x, len = b[1].y;
        ct++;
        FOR (i, 2, n){
            if (2 * (mx + b[i].x) > (len + b[i].y)){
                mx += b[i].x, len += b[i].y;
                ct++;
            }
        }
        ans = max (ans, ct);
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