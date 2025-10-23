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
    string s;
    cin >> n >> s;

    s = ' ' + s;
    map<int, int>mp1, mp2;

    if (n & 1) {
        int ans = 0;

        FOR (i, 2, n) {
            if (i & 1) {
                mp2[s[i]]++;
            } else {
                mp1[s[i]]++;
            }
        }
        int mx1 = 0, mx2 = 0;

        FOR (i, 'a', 'z') {
            mx1 = max (mx1, mp1[i]);
            mx2 = max (mx2, mp2[i]);
        }

        ans = (n - (mx1 + mx2));

        FOR (i, 2, n) {
            if (i & 1) {
                mp2[s[i]]--;
                mp2[s[i - 1]]++;
            } else {
                mp1[s[i]]--;
                mp1[s[i - 1]]++;
            }
            int mx1 = 0, mx2 = 0;

            FOR (i, 'a', 'z') {
                mx1 = max (mx1, mp1[i]);
                mx2 = max (mx2, mp2[i]);
            }
            ans = min (ans, (n - mx1 - mx2));
        }

        cout << ans << endl;
    } else {

        FOR2 (i, 1, n, 2) {
            mp1[s[i]]++;
        }
        FOR2 (i, 2, n, 2) {
            mp2[s[i]]++;
        }

        int mx1 = 0, mx2 = 0;

        FOR (i, 'a', 'z') {
            mx1 = max (mx1, mp1[i]);
            mx2 = max (mx2, mp2[i]);
        }

        cout << (n - mx1 - mx2) << endl;
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