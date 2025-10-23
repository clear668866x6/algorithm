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
    cin >> n >> m;

    V<int>p (100010, 0);

    FOR (i, 1, 100000)p[i] = i;

    function<int (int)>find = [&] (int x) {
        if (x != p[x])p[x] = find (p[x]);
        return p[x];
        };

    V<PII>w;

    FOR (i, 1, n) {
        int a, b;
        cin >> a >> b;
        w.eb (a, b);
    }

    struct E {
        int d, x, y;
        bool operator<(const E& t)const {
            return d > t.d;
        }
    };

    function<int (PII, PII)>d = [&] (PII a, PII b) {
        return abs (a.fi - b.fi) + abs (a.se - b.se);
        };

    priority_queue<E>q;

    FOR (i, 0, n - 1) {
        FOR (j, i + 1, n - 1) {
            q.push ({ d (w[i],w[j]),i + 1,j + 1 });
        }
    }

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            w.eb (x, y);
            FOR (i, 0, n - 1) {
                q.push ({ d (w[i],w[n]),i + 1,n + 1 });
            }
            n++;
        }
        else if (op == 2) {
            int cnt = 0;
            FOR (i, 1, n) {
                if (find (i) == i) {
                    cnt++;
                }
            }
            if (cnt == 1) {
                cout << -1 << endl;
            }
            else {
                int d = -1;
                while (q.sz) {
                    E t = q.top ();
                    q.pop ();
                    if (find (t.x) == find (t.y))continue;
                    if (d == -1) {
                        d = t.d;
                        p[find (t.x)] = find (t.y);
                    }
                    else if (d == t.d) {
                        p[find (t.x)] = find (t.y);
                    }
                    else {
                        q.push (t);
                        break;
                    }
                }
                cout << d << endl;
            }
        }
        else {
            int x, y;
            cin >> x >> y;
            if (find (x) == find (y)) {
                Yes;
            }
            else {
                No;
            }
        }
    }


}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}