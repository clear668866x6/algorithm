#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> p[i];
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> mx(n + 1, 0);
    for (int i = 1; i <= n; i++) mx[i] = max(mx[i - 1], p[i]);

    int tfalse = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'L' && s[i] == 'R') {
            if (mx[i - 1] != i - 1) {
                tfalse++;
            }
        }
    }

    while (q--) {
        int x;
        cin >> x;
        if (x - 1 >= 1) {
            if (s[x - 1] == 'L' && s[x] == 'R' && mx[x - 1] != x - 1) tfalse--;
        }

        if (x + 1 <= n) {
            if (s[x] == 'L' && s[x + 1] == 'R' && mx[x] != x) tfalse--;
        }
        if (s[x] == 'L')
            s[x] = 'R';
        else
            s[x] = 'L';
        if (x - 1 >= 1) {
            if (s[x - 1] == 'L' && s[x] == 'R' && mx[x - 1] != x - 1) tfalse++;
        }

        if (x + 1 <= n) {
            if (s[x] == 'L' && s[x + 1] == 'R' && mx[x] != x) tfalse++;
        }

        if (tfalse) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}