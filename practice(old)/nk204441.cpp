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
    struct E{
        int val, id;
        bool operator<(const E& t)const{
            return val > t.val;
        }
    };
    V<E>w (n);
    int s = 0;

    FOR (i, 0, n - 1){
        cin >> w[i].val;
        w[i].val = (1LL << w[i].val);
        w[i].id = i;
        s += w[i].val;
    }

    if (s < (1LL << 30)){
        cout << "impossible" << endl;
    } else{
        string a (n, '0');
        sort (ALL (w));

        int v = (1LL << 30);

        FOR (i, 0, n - 1){
            if (w[i].val <= v){
                v -= w[i].val;
                a[w[i].id] = '1';
            }
        }
        cout << a << endl;
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