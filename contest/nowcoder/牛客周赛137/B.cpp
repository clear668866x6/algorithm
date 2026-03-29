#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    s = ' ' + s;

    deque<char> q;

    int f = false;

    for (int i = 1; i <= n; i++) {
        if (s[i] == '-') {
            if (!f) {
                if (!q.empty()) {
                    q.pop_back();
                }
            } else {
                if (!q.empty()) {
                    q.pop_front();
                }
            }
        } else if (s[i] == '!') {
            f ^= 1;
        } else {
            if (!f) {
                q.push_back(s[i]);
            } else {
                q.push_front(s[i]);
            }
        }
    }

    if (q.empty()) {
        cout << "Empty\n";
    } else {
        for (auto x : q) cout << x;
        cout << '\n';
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