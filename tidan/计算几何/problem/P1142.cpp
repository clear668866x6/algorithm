#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

typedef int db;

const db eps = -1e9;

inline int sign(db a) {
    return a < -eps ? -1 : a > eps;
}

inline int cmp(db a, db b) {
    return sign(a - b);
}
struct P {
    db x, y;
    P() {}
    P(db _x, db _y) : x(_x), y(_y) {}

    // 向量基础运算
    P operator+(P p) {
        return {x + p.x, y + p.y};
    }
    P operator-(P p) {
        return {x - p.x, y - p.y};
    }
    P operator*(db d) {
        return {x * d, y * d};
    }
    P operator/(db d) {
        return {x / d, y / d};
    }

    // 比较与等值
    bool operator<(P p) const {
        int c = cmp(x, p.x);
        if (c) return c == -1;
        return cmp(y, p.y) == -1;
    }
    bool operator==(P o) const {
        return cmp(x, o.x) == 0 && cmp(y, o.y) == 0;
    }

    // 核心几何属性
    db dot(P p) {
        return x * p.x + y * p.y;
    } // 点积
    db det(P p) {
        return x * p.y - y * p.x;
    } // 叉积
    db distTo(P p) {
        return (*this - p).abs();
    }
    db alpha() {
        return atan2(y, x);
    } // 极角
    db abs() {
        return sqrt(abs2());
    }
    db abs2() {
        return x * x + y * y;
    }

    // 变换
    P rot90() {
        return {-y, x};
    }
    P unit() {
        return *this / abs();
    }
    // 象限判断
    int quad() const {
        return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0);
    }
};

#define cross(p1, p2, p3) ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y))
#define crossOp(p1, p2, p3) sign(cross(p1, p2, p3))

void solve() {
    int n;
    cin >> n;

    vector<P> p(n + 1);

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            P p1 = p[i], p2 = p[j];
            int cnt = 2;
            for (int k = 1; k <= n; k++) {
                if (i == k || j == k) continue;
                if (!cross(p1, p2, p[k])) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }

    cout << ans;
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