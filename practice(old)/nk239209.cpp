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
    int l, r, k;
    cin >> l >> r >> k;

    function<i128 (i128, i128)>qmi = [&] (i128 a, i128 b) {
        i128 res = 1;
        while (b) {
            if (b & 1)res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
        };

    if (k == 0) {
        if (l > 1) {
            cout << "None." << endl;
            RE;
        }
        if (l <= 0 && r >= 0) {
            cout << "0 ";
        }

        if (l <= 1 && r >= 1) {
            cout << "1 ";
        }
        cout << endl;
        RE;
    }

    if (k == 1) {
        if (l <= 1 && r >= 1) {
            cout << 1 << endl;
        } else {
            cout << "None." << endl;
        }
        RE;
    }

    V<int>ans;

    i128 p = qmi (2, 63);

    FOR (i, 0, 63) {
        i128 t = qmi (k, i);
        if (t > p)break;
        if (t >= l && t <= r) {
            ans.eb (t);
        }
    }

    if (!ans.sz) {
        cout << "None." << endl;
    } else {
        for (auto x : ans)cout << x << ' ';
        cout << endl;
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