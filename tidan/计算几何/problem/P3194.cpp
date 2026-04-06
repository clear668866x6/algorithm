#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

#include <bits/stdc++.h>
using namespace std;

typedef double db;

const db eps = 1e-9;

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
    int idx;
    P() {}
    P(db _x, db _y) : x(_x), y(_y) {}
    P(db _x, db _y, int _idx) : x(_x), y(_y), idx(_idx) {}

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
    P rot(db an) {
        return {x * cos(an) - y * sin(an), x * sin(an) + y * cos(an)};
    }

    // 象限判断
    int quad() const {
        return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0);
    }
};
// cross 是三点共线，如果共线值为0,p1是共同顶点，就是(p2-p1)与(p3-p1)的叉积
#define cross(p1, p2, p3) ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y))
#define crossOp(p1, p2, p3) sign(cross(p1, p2, p3))

// 两点距离
db dist(P p1, P p2) {
    db x = p1.x - p2.x;
    db y = p1.y - p2.y;
    return sqrt(x * x + y * y);
}

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

// 判断点 p 是否在线段 p1p2 上
// 原理：1. p 与 p1p2 共线（叉积为0） 2. p 的坐标在 p1p2 的范围内（点积判断）
bool onSeg(P p1, P p2, P p) {
    // crossOp 是你之前定义的：sign(cross(p, p1, p2))
    // 为 0 说明点 p 在直线 p1p2 上
    // dot 判断点是否在以 p1p2 为对角线的矩形内（包含端点）
    return crossOp(p1, p2, p) == 0 && sign((p1 - p).dot(p2 - p)) <= 0;
}

// ---------------- 核心多边形算法 ----------------

// 求多边形面积 (有向面积)
// 传入的 ps 必须是按顺时针或逆时针给出的点集。
// 返回值为正表示逆时针，为负表示顺时针，建议外部套一个 abs()。
db area(vector<P> ps) {
    db ret = 0;
    for (int i = 0; i < ps.size(); i++) ret += ps[i].det(ps[(i + 1) % ps.size()]);
    return ret / 2;
}

// 判断点 p 是否在多边形 ps 内部 (射线法/转角法)
// 返回值: 2 代表在多边形内部，1 代表在多边形边界上，0 代表在多边形外部
int contain(vector<P> ps, P p) {
    int n = ps.size(), ret = 0;
    for (int i = 0; i < n; i++) {
        P u = ps[i], v = ps[(i + 1) % n];
        if (onSeg(u, v, p)) return 1; // 需依赖你基础模板里的 onSeg 判断点是否在线段上
        if (cmp(u.y, v.y) <= 0) swap(u, v);
        if (cmp(p.y, u.y) > 0 || cmp(p.y, v.y) <= 0) continue;
        ret ^= crossOp(p, u, v) > 0;
    }
    return ret * 2;
}

// 求严格凸包 (Andrew 算法 / 单调栈)
// 返回逆时针排列的凸包点集。不包含共线的冗余点。
// 注意：如果原图退化成一条线段，需特判！
vector<P> convexHull(vector<P> ps) {
    int n = ps.size();
    if (n <= 1) return ps;
    sort(ps.begin(), ps.end()); // 按 x 第一关键字，y 第二关键字排序
    vector<P> qs(n * 2);
    int k = 0;
    // 下凸壳
    for (int i = 0; i < n; qs[k++] = ps[i++])
        while (k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
    // 上凸壳
    for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--])
        while (k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
    qs.resize(k - 1);
    return qs;
}

// 求非严格凸包
// 保留凸壳边界上共线的点。
// 警告: 使用前需要将 ps 去重 (unique)，否则共线点处理会出错。
vector<P> convexHullNonStrict(vector<P> ps) {
    int n = ps.size();
    if (n <= 1) return ps;
    sort(ps.begin(), ps.end());
    vector<P> qs(n * 2);
    int k = 0;
    for (int i = 0; i < n; qs[k++] = ps[i++])
        while (k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) < 0) --k; // 注意这里是 < 0
    for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--])
        while (k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) < 0) --k;
    qs.resize(k - 1);
    return qs;
}

// 求凸多边形直径 (旋转卡壳)
// ps 必须是逆时针给出的凸包点集。
// 返回凸包上距离最远的两个点之间的距离。
db convexDiameter(vector<P> ps) {
    int n = ps.size();
    if (n <= 1) return 0;
    int is = 0, js = 0;
    for (int k = 1; k < n; k++) is = ps[k] < ps[is] ? k : is, js = ps[js] < ps[k] ? k : js;
    int i = is, j = js;
    db ret = ps[i].distTo(ps[j]);
    do {
        // 利用叉积判断下一个点推进的方向，保持平行线卡住多边形
        if ((ps[(i + 1) % n] - ps[i]).det(ps[(j + 1) % n] - ps[j]) >= 0)
            (++j) %= n;
        else
            (++i) %= n;
        ret = max(ret, ps[i].distTo(ps[j]));
    } while (i != is || j != js);
    return ret;
}

// 半平面交 / 凸多边形切割
// 用有向直线 q1->q2 切割凸多边形 ps，保留直线左侧的部分。
// ps 必须是逆时针的凸包，返回的也是逆时针的凸包。
vector<P> convexCut(const vector<P> &ps, P q1, P q2) {
    vector<P> qs;
    int n = ps.size();
    for (int i = 0; i < n; i++) {
        P p1 = ps[i], p2 = ps[(i + 1) % n];
        int d1 = crossOp(q1, q2, p1), d2 = crossOp(q1, q2, p2);
        if (d1 >= 0) qs.push_back(p1); // p1 在左侧或直线上，保留
        if (d1 * d2 < 0) qs.push_back(isLL(p1, p2, q1, q2)); // 跨越直线，求交点并保留 (需依赖 isLL 函数)
    }
    return qs;
}

// ---------------- 核心圆算法 ----------------

// 判断两圆关系
// 返回值: 4:相离, 3:外切, 2:相交, 1:内切, 0:包含
int type(P o1, db r1, P o2, db r2) {
    db d = o1.distTo(o2);
    if (cmp(d, r1 + r2) == 1) return 4;
    if (cmp(d, r1 + r2) == 0) return 3;
    if (cmp(d, abs(r1 - r2)) == 1) return 2;
    if (cmp(d, abs(r1 - r2)) == 0) return 1;
    return 0;
}

// 直线与圆的交点
// o:圆心, r:半径, p1,p2:直线上的两个点
// 返回交点数组，沿 p1->p2 方向排序。可能返回 0, 1, 2 个点。
vector<P> isCL(P o, db r, P p1, P p2) {
    if (cmp(abs((o - p1).det(p2 - p1) / p1.distTo(p2)), r) > 0) return {}; // 相离
    db x = (p1 - o).dot(p2 - p1), y = (p2 - p1).abs2(), d = x * x - y * ((p1 - o).abs2() - r * r);
    d = max(d, (db)0.0);
    P m = p1 - (p2 - p1) * (x / y); // 垂足
    P dr = (p2 - p1) * (sqrt(d) / y); // 偏移量
    return {m - dr, m + dr};
}

// 两圆交点
// 注意: 使用前需要确保两圆不完全重合！
// 保证返回的交点顺着圆 o1 的逆时针方向。可能返回 0, 1, 2 个点。
vector<P> isCC(P o1, db r1, P o2, db r2) {
    db d = o1.distTo(o2);
    if (cmp(d, r1 + r2) == 1) return {}; // 外离
    if (cmp(d, abs(r1 - r2)) == -1) return {}; // 内含
    d = min(d, r1 + r2); // 防止精度误差导致的 d 略大于 r1+r2
    db y = (r1 * r1 + d * d - r2 * r2) / (2 * d), x = sqrt(r1 * r1 - y * y);
    P dr = (o2 - o1).unit();
    P q1 = o1 + dr * y, q2 = dr.rot90() * x;
    return {q1 - q2, q1 + q2};
}

// 求两圆公切线
// 传入的符号代表求哪种切线：外公切线传 r1-r2，内公切线传 r1+r2。
// 点 p 到圆切线直接令 r2 = 0 即可。
// 返回值为 pair 数组，每对 pair 是 {切点1, 切点2}。
vector<pair<P, P>> tanCC(P o1, db r1, P o2, db r2) {
    P d = o2 - o1;
    db dr = r1 - r2, d2 = d.abs2(), h2 = d2 - dr * dr;
    if (sign(d2) == 0 || sign(h2) < 0) return {}; // 同心圆或包含关系无公切线
    h2 = max(0.0, h2);
    vector<pair<P, P>> ret;
    for (db sign : {-1, 1}) {
        P v = (d * dr + d.rot90() * sqrt(h2) * sign) / d2;
        ret.push_back({o1 + v * r1, o2 + v * r2});
    }
    if (sign(h2) == 0) ret.pop_back(); // 相切时只有一条
    return ret;
}

// 辅助函数：求两向量夹角
db rad(P p1, P p2) {
    return atan2(p1.det(p2), p1.dot(p2));
}

// 求圆与三角形的有向面积交
// 圆心默认在原点 (0,0)，半径为 r。三角形三个顶点为 原点, p1, p2。
// 计算圆和三角形交集的面积，可用于将任意多边形三角剖分后求与圆的面积交。
db areaCT(db r, P p1, P p2) {
    vector<P> is = isCL(P(0, 0), r, p1, p2);
    if (is.empty()) return r * r * rad(p1, p2) / 2;
    bool b1 = cmp(p1.abs2(), r * r) == 1, b2 = cmp(p2.abs2(), r * r) == 1;
    if (b1 && b2) {
        if (sign((p1 - is[0]).dot(p2 - is[0])) <= 0 && sign((p1 - is[1]).dot(p2 - is[1])) <= 0)
            return r * r * (rad(p1, is[0]) + rad(is[1], p2)) / 2 + is[0].det(is[1]) / 2;
        else
            return r * r * rad(p1, p2) / 2;
    }
    if (b1) return (r * r * rad(p1, is[0]) + is[0].det(p2)) / 2;
    if (b2) return (p1.det(is[1]) + r * r * rad(is[1], p2)) / 2;
    return p1.det(p2) / 2;
}

// 三角形内心 (角平分线交点)
P inCenter(P A, P B, P C) {
    double a = (B - C).abs(), b = (C - A).abs(), c = (A - B).abs();
    return (A * a + B * b + C * c) / (a + b + c);
}

// 三角形外心 (中垂线交点)
P circumCenter(P a, P b, P c) {
    P bb = b - a, cc = c - a;
    double db = bb.abs2(), dc = cc.abs2(), d = 2 * bb.det(cc);
    return a - P(bb.y * dc - cc.y * db, cc.x * db - bb.x * dc) / d;
}

// 三角形垂心 (高线交点)
P othroCenter(P a, P b, P c) {
    P ba = b - a, ca = c - a, bc = b - c;
    double Y = ba.y * ca.y * bc.y;
    double A = ca.x * ba.y - ba.x * ca.y;
    double x0 = (Y + ca.x * ba.y * b.x - ba.x * ca.y * c.x) / A;
    double y0 = -ba.x * (x0 - c.x) / ba.y + ca.y;
    return {x0, y0};
}

// 最小圆覆盖 (随机增量法)
// 给定点集 ps，求能覆盖所有点的最小圆的 {圆心, 半径}。
// 期望复杂度 O(N)。注意最开始一定要 random_shuffle，防退化。
pair<P, db> min_circle(vector<P> ps) {
    random_shuffle(ps.begin(), ps.end());
    int n = ps.size();
    P o = ps[0];
    db r = 0;
    for (int i = 1; i < n; i++)
        if (o.distTo(ps[i]) > r + eps) { // 不在当前圆内
            o = ps[i], r = 0;
            for (int j = 0; j < i; j++)
                if (o.distTo(ps[j]) > r + eps) {
                    o = (ps[i] + ps[j]) / 2;
                    r = o.distTo(ps[i]); // 以 ij 为直径
                    for (int k = 0; k < j; k++)
                        if (o.distTo(ps[k]) > r + eps) {
                            o = circumCenter(ps[i], ps[j], ps[k]); // ijk 三点共圆
                            r = o.distTo(ps[i]);
                        }
                }
        }
    return {o, r};
}

void solve() {
    int n;
    cin >> n;

    vector<P> w(n);
    for (int i = 0; i < n; i++) {
        db a, b;
        cin >> a >> b;
        w[i] = {a, b, i + 1};
    }

    sort(w.begin(), w.end(), [&](P a, P b) {
        if (cmp(a.x, b.x) != 0) return cmp(a.x, b.x) < 0;
        return cmp(a.y, b.y) > 0;
    });

    vector<P> v;

    for (int i = 0; i < n; i++) {
        if (!i || cmp(w[i - 1].x, w[i].x) != 0) {
            v.push_back(w[i]);
        }
    }

    vector<P> p = convexHull(v);

    int mid = 0;
    for (int i = 1; i < p.size(); i++) {
        if (cmp(p[i].x, p[mid].x) > 0) {
            mid = i;
        }
    }

    vector<int> ans;

    for (int i = mid; i < p.size(); i++) {
        ans.push_back(p[i].idx);
    }

    if (mid != 0) {
        ans.push_back(p[0].idx);
    }

    sort(ans.begin(), ans.end());

    for (auto x : ans) cout << x << ' ';
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