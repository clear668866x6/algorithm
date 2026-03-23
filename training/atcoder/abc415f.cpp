#include <bits/stdc++.h>
#include <iterator>
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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;

    map<char, set<int>> mp, mp2;

    FOR(j, 0, 25) {
        FOR(i, 1, n) {
            if (s[i] == j + 'a') {
                int t = i;
                while (t <= n && s[t] == j + 'a') {
                    t++;
                }
                cerr << char(j + 'a') << ' ' << i << ' ' << t - 1 << endl;
                mp[j].insert(i);
                mp[j].insert(t - 1);
                mp2[j].insert(t - i);
                i = t - 1;
            }
        }
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i;
            char x;
            cin >> i >> x;
            auto l1 = mp[s[i] - 'a'].lower_bound(i);
            auto r1 = prev(mp[s[i] - 'a'].upper_bound(i));
            int len = *r1 - *l1 + 1;
            if (i == *l1 && i == *r1) {
                mp[s[i] - 'a'].erase(i);
                mp[s[i] - 'a'].erase(i);
                mp2[s[i] - 'a'].erase(len);
            } else if (i == *l1 && i != *r1) {
                mp[s[i] - 'a'].erase(i);
                mp[s[i] - 'a'].insert(i + 1);
                mp2[s[i] - 'a'].erase(len);
                mp2[s[i] - 'a'].insert(len - 1);
            } else if (i != *l1 && i == *r1) {
                mp[s[i] - 'a'].erase(i);
                mp[s[i] - 'a'].insert(i - 1);
                mp2[s[i] - 'a'].erase(len);
                mp2[s[i] - 'a'].insert(len - 1);
            } else {
                mp[s[i] - 'a'].insert(i - 1);
                mp[s[i] - 'a'].insert(i + 1);
                mp2[s[i] - 'a'].erase(len);
                mp2[s[i] - 'a'].insert(i - *l1);
                mp2[s[i] - 'a'].insert(*r1 - i);
            }
            s[i] = x;

            auto l2 = mp[s[i] - 'a'].upper_bound(i);
            auto r2 = mp[s[i] - 'a'].lower_bound(i);
            if (l2 != mp[s[i] - 'a'].end() && r2 != mp[s[i] - 'a'].begin()) {
                r2--;
                if (i + 1 == *l2 && i - 1 == *r2) {
                    mp[s[i] - 'a'].erase(i - 1);
                    mp[s[i] - 'a'].erase(i + 1);
                    mp2[s[i] - 'a'].erase(*r2 - *(prev(r2)) + 1);
                    mp2[s[i] - 'a'].erase(*next(l2) - *l2 + 1);
                    mp2[s[i] - 'a'].insert(*next(l2) - *prev(r2) + 1);
                } else if (i + 1 == *l2 && i - 1 != *r2) {
                    mp[s[i] - 'a'].erase(i + 1);
                    mp2[s[i] - 'a'].erase(*r2 - *(prev(r2)) + 1);
                    mp2[s[i] - 'a'].insert(*r2 - *(prev(r2)) + 2);
                } else if (i + 1 != *l2 && i - 1 == *r2) {

                    mp[s[i] - 'a'].erase(i - 1);
                    mp2[s[i] - 'a'].erase(*next(l2) - *l2 + 1);
                    mp2[s[i] - 'a'].insert(*next(l2) - *l2 + 1 + 2);
                } else {
                    mp[s[i] - 'a'].insert(i);
                    mp[s[i] - 'a'].insert(i);
                    mp2[s[i] - 'a'].insert(1);
                }
            } else if (l2 != mp[s[i] - 'a'].end() && r2 == mp[s[i] - 'a'].begin()) {
                if (i + 1 == *l2) {
                    mp[s[i] - 'a'].erase(i + 1);
                    mp[s[i] - 'a'].insert(i);
                    mp2[s[i] - 'a'].erase(*next(l2) - *l2 + 1);
                    mp2[s[i] - 'a'].insert(*next(l2) - *l2 + 2);

                } else {

                    mp[s[i] - 'a'].insert(i);
                    mp[s[i] - 'a'].insert(i);
                    mp2[s[i] - 'a'].insert(1);
                }
            } else if (l2 == mp[s[i] - 'a'].end() && r2 != mp[s[i] - 'a'].begin()) {
                r2--;
                if (i - 1 == *r2) {

                    mp[s[i] - 'a'].erase(i - 1);
                    mp[s[i] - 'a'].insert(i);
                    mp2[s[i] - 'a'].erase(*r2 - *prev(r2) + 1);
                    mp2[s[i] - 'a'].insert(*r2 - *prev(r2) + 2);
                } else {

                    mp[s[i] - 'a'].insert(i);
                    mp[s[i] - 'a'].insert(i);
                    mp2[s[i] - 'a'].insert(1);
                }
            } else {

                mp[s[i] - 'a'].insert(i);
                mp[s[i] - 'a'].insert(i);
                mp2[s[i] - 'a'].insert(1);
            }

        } else {
            int l, r;
            cin >> l >> r;

            int ans = 0;

            FOR(c, 0, 25) {
                if (mp2[c].empty()) continue;
                ans = max(ans, *mp2[c].rbegin());
            }
            cout << ans << endl;
        }
    }
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