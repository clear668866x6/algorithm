#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> c1;
    vector<char> c2;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        c1.push_back(x);
    }

    for (int i = 2; i <= n; i++) {
        char c;
        cin >> c;
        c2.push_back(c);
    }

    while (!c2.empty()) {
        int t1 = c1.back();
        c1.pop_back();
        int t2 = c1.back();
        c1.pop_back();
        char c = c2.back();
        c2.pop_back();
        if (c == '+') {
            c1.push_back(t1 + t2);
        } else if (c == '-') {
            c1.push_back(t2 - t1);
        } else if (c == '*') {
            c1.push_back(t1 * t2);
        } else {
            if (!t1) {
                cout << "ERROR: " << t2 << "/0";
                return;
            }
            c1.push_back(t2 / t1);
        }
    }

    cout << c1.back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}