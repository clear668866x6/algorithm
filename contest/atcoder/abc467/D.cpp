#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    i64 x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    struct P {
        i64 a, b;
        P() {}
        P(i64 _a, i64 _b) : a(_a), b(_b) {}

        bool operator==(P p) {
            return ((i128)p.a * b - p.b * a) == 0;
        }
    };

    auto get = [&](i64 a1, i64 b1, i64 a2, i64 b2) {
        if (a1 - a2 != 0) {
            return P(a2 - a1, b1 - b2);
        } else {
            return P(a1 - a2, b2 - b1);
        }
    };

    P p1 = get(x1, y1, x2, y2);
    P p2 = get(x3, y3, x4, y4);

    if (p1 == p2) {
        P p3((x3 + x4) - (x1 + x2), (y3 + y4) - (y1 + y2));
        if ((i128)p3.a * p1.a == (i128)p3.b * p1.b) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        cout << "Yes\n";
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