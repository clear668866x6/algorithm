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
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;

    string s1 = " ", s2 = " ";
    n *= 2;
    FOR(i, 1, n) {
        if (i & 1)
            s1 += 'A', s2 += 'B';
        else
            s1 += 'B', s2 += 'A';
    }

    auto calc = [&](string s1) {
        int ans1 = 0;

        set<int> ca, cb;

        FOR(i, 1, n) {
            if (s1[i] == s[i]) continue;
            if (s[i] == 'A')
                ca.insert(i);
            else
                cb.insert(i);
        }

        FOR(i, 1, n) {
            if (s1[i] == s[i]) continue;

            if (s[i] == 'A' && ca.count(i)) {
                int t = *cb.begin();
                ans1 += (t - i);
                cb.erase(t);
                ca.erase(i);
            } else if (s[i] == 'B' && cb.count(i)) {
                int t = *ca.begin();
                ans1 += (t - i);
                ca.erase(t);
                cb.erase(i);
            }
        }
        return ans1;
    };

    cout << min(calc(s1), calc(s2)) << endl;
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