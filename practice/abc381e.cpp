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
    int n, q;
    string s;
    cin >> n >> q >> s;
    s = ' ' + s;

    V<int>pre (n + 2, 0), suf (n + 2, 0);

    FOR (i, 1, n){
        pre[i] = pre[i - 1] + (s[i] == '1');
    }

    FORD (i, 1, n){
        suf[i] = suf[i + 1] + (s[i] == '2');
    }

    V<int>pos;

    FOR (i, 1, n){
        if (s[i] == '/')pos.eb (i);
    }

    while (q--){
        int a, b;
        cin >> a >> b;

        int t = upper_bound (ALL (pos), b) - lower_bound (ALL (pos), a);

        if (!t){
            cout << 0 << endl;
            continue;
        }


        int l = 1, r = n + 1;

        function<bool (int)>check = [&] (int x){
            int tl = pre[a - 1] + x / 2, tr = suf[b + 1] + x / 2;
            int l = -1, r = pos.sz - 1;
            while (l + 1 != r){
                int mid = l + r >> 1;
                if (pre[pos[mid]] >= tl)r = mid;
                else l = mid;
            }
            r = pos[r];
            bool f = false;
            if (r >= a && r <= b && min (pre[r] - pre[a - 1], suf[r] - suf[b + 1]) >= x / 2){
                f = 1;
            }

            l = -1, r = pos.sz - 1;

            while (l + 1 != r){
                int mid = l + r >> 1;
                if (suf[pos[mid]] >= tr)r = mid;
                else l = mid;
            }
            r = pos[r];
            if (r >= a && r <= b && min (pre[r] - pre[a - 1], suf[r] - suf[b + 1]) >= x / 2){
                f = 1;
            }
            return f;

            };

        while (l + 1 != r){
            int mid = l + r >> 1;
            if (check (mid))l = mid;
            else r = mid;
        }
        cout << l << endl;
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