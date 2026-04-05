#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

typedef int db;

const db eps = -1e9;

inline int sign(db a) {
    // return a < -eps ? -1 : a > eps;
    if (!a) return 0;
    return a < 0 ? -1 : 1;
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
// cross 是三点共线，如果共线值为0,p1是共同顶点，就是(p2-p1)与(p3-p1)的叉积
#define cross(p1, p2, p3) ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y))
#define crossOp(p1, p2, p3) sign(cross(p1, p2, p3))

// 直线相交判定与交点
bool chkLL(P p1, P p2, P q1, P q2) {
    db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
    return sign(a1 + a2) != 0;
}

P isLL(P p1, P p2, P q1, P q2) {
    db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
    return (p1 * a2 + p2 * a1) / (a1 + a2);
}

// 判断区间是否相交
bool intersect(db l1, db r1, db l2, db r2) {
    if (l1 > r1) swap(l1, r1);
    if (l2 > r2) swap(l2, r2);
    return !(cmp(r1, l2) == -1 || cmp(r2, l1) == -1);
}

// 线段相交判定（非严格）
bool isSS(P p1, P p2, P q1, P q2) {
    return intersect(p1.x, p2.x, q1.x, q2.x) && intersect(p1.y, p2.y, q1.y, q2.y) &&
           crossOp(p1, p2, q1) * crossOp(p1, p2, q2) <= 0 && crossOp(q1, q2, p1) * crossOp(q1, q2, p2) <= 0;
}

// 线段相交判定（严格）
bool isSS_strict(P p1, P p2, P q1, P q2) {
    return crossOp(p1, p2, q1) * crossOp(p1, p2, q2) < 0 && crossOp(q1, q2, p1) * crossOp(q1, q2, p2) < 0;
}

// 判断m是否在a, b之间
bool isMiddle(db a, db m, db b) {
    return sign(a - m) == 0 || sign(b - m) == 0 || (a < m != b < m);
}

bool isMiddle(P a, P m, P b) {
    return isMiddle(a.x, m.x, b.x) && isMiddle(a.y, m.y, b.y);
}

// 点q在直线p1p2上的投影
P proj(P p1, P p2, P q) {
    P dir = p2 - p1;
    return p1 + dir * (dir.dot(q - p1) / dir.abs2());
}

// 点q关于直线p1p2的反射点
P reflect(P p1, P p2, P q) {
    return proj(p1, p2, q) * 2 - q;
}

// 点q到线段p1p2的最短距离
db nearest(P p1, P p2, P q) {
    if (p1 == p2) return p1.distTo(q);
    P h = proj(p1, p2, q);
    if (isMiddle(p1, h, p2)) return q.distTo(h);
    return min(p1.distTo(q), p2.distTo(q));
}

// 极角排序
void polarSort(vector<P> &ps) {
    sort(ps.begin(), ps.end(), [&](P a, P b) {
        int qa = a.quad(), qb = b.quad();
        if (qa != qb) return qa < qb;
        return sign(a.det(b)) > 0;
    });
}

void solve() {
    string s;
    vector<array<int, 2>> p;
    int a, b;
    for (int i = 1; i <= 4; i++) {
        cin >> s;
        char c;
        int x, y;
        stringstream ss;
        ss << s;
        ss >> c >> x >> c >> y >> c;
        if (i != 4) {
            p.push_back({x, y});
        } else {
            a = x, b = y;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (p[i][0] == a && p[i][1] == b) {
            cout << 4;
            return;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            P pa({p[i][0], p[i][1]}), pb({p[j][0], p[j][1]}), pc({a, b});
            if (!cross(pa, pb, pc) && isMiddle(pa, pc, pb)) {
                cout << 3;
                return;
            }
        }
    }

    P p0({p[0][0], p[0][1]}), p1({p[1][0], p[1][1]}), p2({p[2][0], p[2][1]}), p3({a, b});

    int c1 = crossOp(p0, p1, p3);
    int c2 = crossOp(p1, p2, p3);
    int c3 = crossOp(p2, p0, p3);

    if ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0)) {
        cout << 1;
    } else {
        cout << 2;
    }
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