#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) (int)(x).size()

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int l = 0, r = 0;
    s = ' ' + s;
    FOR(i, 1, n) {
        if (s[i] == 'I') {
            l = i - 1, r = i + 1;
            break;
        }
    }

    while (k--) {
        string x;
        cin >> x;
        if (x == "backspace") {
            if (l >= 1 && s[l] == '(' && r <= n && s[r] == ')') {
                l--, r++;
            } else if (l - 1 >= 0) {
                l--;
            }
        } else {
            if (r <= n) r++;
        }
    }

    FOR(i, 1, l) cout << s[i];
    cout << 'I';
    FOR(i, r, n) cout << s[i];
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}