#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using Type = double; // 类型开关：想用整数就改成 long long，想用浮点就改成 double
using db = double; // 辅助浮点类型：无论坐标是整还是浮，求长、角度等必然是浮点数的保留 db

const db eps = 1e-9;

template<typename T> inline int sign(T a) {
    if constexpr (is_integral_v<T>) { // 如果当前开启了整数模式 (long long)
        if (a == 0) return 0;
        return a < 0 ? -1 : 1;
    } else { // 如果当前开启了浮点模式 (double)
        if (a < -eps) return -1;
        if (a > eps) return 1;
        return 0;
    }
}

template<typename T> inline int cmp(T a, T b) {
    return sign(a - b);
}

// ======================= 点与向量基础 =======================
struct P {
    Type x, y; // 坐标根据开关自动变成 int 或 double

    P() {}
    P(Type _x, Type _y) : x(_x), y(_y) {}

    // 【向量基础运算】
    P operator+(P p) {
        return {x + p.x, y + p.y};
    }
    P operator-(P p) {
        return {x - p.x, y - p.y};
    }
    P operator*(Type d) {
        return {x * d, y * d};
    }
    //  注意：如果开启了整数模式，这里的除法会向下取整！涉及精确比例缩放请用 double！
    P operator/(Type d) {
        return {x / d, y / d};
    }

    // 【比较操作】
    // 优先比较 x，x相等比较 y。主要用于极角排序或求凸包前的预处理排序
    bool operator<(P p) const {
        int c = cmp(x, p.x);
        if (c) return c == -1;
        return cmp(y, p.y) == -1;
    }
    bool operator==(P o) const {
        return cmp(x, o.x) == 0 && cmp(y, o.y) == 0;
    }

    // 点积
    // 几何意义：判断两个向量的方向关系。 >0 同向夹角锐角， =0 垂直， <0 反向夹角钝角
    // 常用场景：求投影长度、判断点是否在线段的“范围”内
    Type dot(P p) {
        return x * p.x + y * p.y;
    }

    // 叉积
    // 几何意义：判断两个向量的旋转关系。当前向量逆时针转到p向量，>0；顺时针转，<0；共线，=0。
    // 常用场景：求三角形有向面积、判断左拐右拐、求凸包
    Type det(P p) {
        return x * p.y - y * p.x;
    }

    // 【长度与角度（永远返回 double）】
    db abs2() {
        return (db)x * x + (db)y * y;
    } // 长度的平方 (避免开根号，比较距离时推荐)
    db abs() {
        return sqrt(abs2());
    } // 向量长度 (真实距离)
    db distTo(P p) {
        return (*this - p).abs();
    } // 两个点之间的距离
    db alpha() {
        return atan2(y, x);
    } // 极角，范围 [-π, π]

    P rot90() {
        return {-y, x};
    } // 逆时针旋转 90 度
    P unit() {
        return *this / abs();
    } // 化为长度为 1 的单位向量
    P rot(db an) { // 逆时针旋转 an 弧度
        return {x * cos(an) - y * sin(an), x * sin(an) + y * cos(an)};
    }

    // 【象限判断】：常用于不依赖 atan2 的极角排序 (防止精度掉坑)
    int quad() const {
        return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0);
    }
};

// 【三点叉积】: 以 p1 为公共端点，求向量 (p1->p2) 与 (p1->p3) 的叉积
// >0: p3 在直线 p1-p2 的左侧 (即 p1->p2->p3 是向左拐)
// <0: p3 在直线 p1-p2 的右侧 (即 p1->p2->p3 是向右拐)
// =0: p1, p2, p3 三点共线
#define cross(p1, p2, p3) ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y))
#define crossOp(p1, p2, p3) sign(cross(p1, p2, p3))

// 两点距离 (外部包装)
db dist(P p1, P p2) {
    return p1.distTo(p2);
}

// ======================= 直线与线段相交判定 =======================

// 1. 判直线相交 (平行返回 false)
bool chkLL(P p1, P p2, P q1, P q2) {
    db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
    return sign(a1 + a2) != 0;
}

// 2. 求两直线交点
// ⚠️警告：如果 Type 是 long long，这里会强制做整数截断！求交点时 Type 必须是 double！
P isLL(P p1, P p2, P q1, P q2) {
    db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
    // 使用比例法求出交点坐标
    return P((p1.x * a2 + p2.x * a1) / (a1 + a2), (p1.y * a2 + p2.y * a1) / (a1 + a2));
}

// 判断一维区间 [l1, r1] 和[l2, r2] 是否有交集 (快速排斥实验辅助函数)
bool intersect(Type l1, Type r1, Type l2, Type r2) {
    if (l1 > r1) swap(l1, r1);
    if (l2 > r2) swap(l2, r2);
    return !(cmp(r1, l2) == -1 || cmp(r2, l1) == -1);
}

// 3. 线段相交判定（非严格）
// 允许两条线段的端点接触、或者部分共线重叠
bool isSS(P p1, P p2, P q1, P q2) {
    return intersect(p1.x, p2.x, q1.x, q2.x) && intersect(p1.y, p2.y, q1.y, q2.y) &&
           crossOp(p1, p2, q1) * crossOp(p1, p2, q2) <= 0 && crossOp(q1, q2, p1) * crossOp(q1, q2, p2) <= 0;
}

// 4. 线段相交判定（严格）
// 必须在两条线段的内部产生十字交叉，碰到端点不算交！
bool isSS_strict(P p1, P p2, P q1, P q2) {
    return crossOp(p1, p2, q1) * crossOp(p1, p2, q2) < 0 && crossOp(q1, q2, p1) * crossOp(q1, q2, p2) < 0;
}

// 5. 判断点 m 是否在 a, b 的一维夹逼区间内
bool isMiddle(Type a, Type m, Type b) {
    return sign(a - m) == 0 || sign(b - m) == 0 || ((a < m) != (b < m));
}
bool isMiddle(P a, P m, P b) {
    return isMiddle(a.x, m.x, b.x) && isMiddle(a.y, m.y, b.y);
}

// ======================= 投影、反射与最近距离 =======================

// 点 q 在直线 p1-p2 上的投影 (垂足)
P proj(P p1, P p2, P q) {
    P dir = p2 - p1;
    // 同样，涉及除法，需确保 Type 为 double
    return p1 + dir * (dir.dot(q - p1) / dir.abs2());
}

// 点 q 关于直线 p1-p2 的反射点 (对称点)
P reflect(P p1, P p2, P q) {
    return proj(p1, p2, q) * 2 - q;
}

// 点 q 到线段 p1-p2 的最短距离 (可能是到端点的距离，也可能是垂直距离)
db nearest(P p1, P p2, P q) {
    if (p1 == p2) return p1.distTo(q);
    P h = proj(p1, p2, q);
    if (isMiddle(p1, h, p2)) return q.distTo(h); // 垂足在线段上
    return min(p1.distTo(q), p2.distTo(q)); // 垂足不在线段上，取两个端点的最小值
}

// 判断点 p 是否在线段 p1-p2 上
// 原理：叉积为 0 保证共线，点积 <= 0 保证 p 在以 p1, p2 为对角线的矩形内部
bool onSeg(P p1, P p2, P p) {
    return crossOp(p1, p2, p) == 0 && sign((p1 - p).dot(p2 - p)) <= 0;
}

// 极角排序板子（按相对原点的角度，象限法）
// 优点：不使用精度极差的 atan2()，利用叉积进行绝对精确的排序
void polarSort(vector<P> &ps) {
    sort(ps.begin(), ps.end(), [&](P a, P b) {
        int qa = a.quad(), qb = b.quad();
        if (qa != qb) return qa < qb;
        return sign(a.det(b)) > 0;
    });
}

// ======================= 核心多边形算法 =======================

// 1. 求多边形面积 (有向面积)
// 传入点集，返回多边形的面积 (若逆时针给出则为正，顺时针为负，外层可以加个 abs)
db area(vector<P> ps) {
    db ret = 0;
    for (int i = 0; i < ps.size(); i++) ret += ps[i].det(ps[(i + 1) % ps.size()]);
    return ret / 2.0;
}

// 2. 判断点 p 是否在多边形 ps 内部 (转角法/射线法结合版)
// 返回值: 2 在多边形内部, 1 在多边形边界上, 0 在多边形外部
int contain(vector<P> ps, P p) {
    int n = ps.size(), ret = 0;
    for (int i = 0; i < n; i++) {
        P u = ps[i], v = ps[(i + 1) % n];
        if (onSeg(u, v, p)) return 1;
        if (cmp(u.y, v.y) <= 0) swap(u, v);
        if (cmp(p.y, u.y) > 0 || cmp(p.y, v.y) <= 0) continue;
        ret ^= crossOp(p, u, v) > 0;
    }
    return ret * 2;
}

// 3. 求严格凸包 (Andrew 算法) - 【计算几何出场率最高】
// 作用：求点集的凸包。返回的是 逆时针 顺序的顶点序列，起点通常是最左下角的点。
// “严格”的含义：凸多边形的边上如果有三个及以上共线的点，会被踢掉，只留下拐角顶点。
vector<P> convexHull(vector<P> ps) {
    int n = ps.size();
    if (n <= 1) return ps;
    sort(ps.begin(), ps.end()); // 预先按 x 第一、y 第二排好序
    vector<P> qs(n * 2);
    int k = 0;
    // 构造下凸壳 (从左向右扫描，只要不向左拐就丢弃)
    for (int i = 0; i < n; qs[k++] = ps[i++])
        while (k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
    // 构造上凸壳 (从右向左回扫)
    for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--])
        while (k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
    qs.resize(k - 1); // 扣掉重复起点
    return qs;
}

// 4. 求非严格凸包
// 作用与严格凸包相同，但 会保留边界上共线的点。
// ⚠️ 警告：使用此函数前必须使用 unique 去除重叠在同一个坐标的点，否则死循环或错乱！
vector<P> convexHullNonStrict(vector<P> ps) {
    int n = ps.size();
    if (n <= 1) return ps;
    sort(ps.begin(), ps.end());
    vector<P> qs(n * 2);
    int k = 0;
    // 这里的判定变成了 < 0，即只有向右拐（凹进去了）才出栈，直行（共线）则保留入栈
    for (int i = 0; i < n; qs[k++] = ps[i++])
        while (k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) < 0) --k;
    for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--])
        while (k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) < 0) --k;
    qs.resize(k - 1);
    return qs;
}

// 5. 旋转卡壳：求凸多边形直径 (最远点对)
// 输入要求：传入的 ps 必须是【已经求好】的 逆时针凸包顶点！
db convexDiameter(vector<P> ps) {
    int n = ps.size();
    if (n <= 1) return 0;
    int is = 0, js = 0;
    for (int k = 1; k < n; k++) is = ps[k] < ps[is] ? k : is, js = ps[js] < ps[k] ? k : js;
    int i = is, j = js;
    db ret = ps[i].distTo(ps[j]);
    do {
        // 利用两对点之间的向量叉积，判断推进方向
        if ((ps[(i + 1) % n] - ps[i]).det(ps[(j + 1) % n] - ps[j]) >= 0)
            (++j) %= n;
        else
            (++i) %= n;
        ret = max(ret, ps[i].distTo(ps[j]));
    } while (i != is || j != js);
    return ret;
}

// 6. 半平面交 / 用直线切割凸多边形
// 作用：用有向直线 q1->q2 像刀一样切开凸多边形 ps，丢掉右侧部分，保留 左侧 部分！
// 输入：ps 必须是逆时针的凸包。返回也是逆时针的新凸包。
vector<P> convexCut(const vector<P> &ps, P q1, P q2) {
    vector<P> qs;
    int n = ps.size();
    for (int i = 0; i < n; i++) {
        P p1 = ps[i], p2 = ps[(i + 1) % n];
        int d1 = crossOp(q1, q2, p1), d2 = crossOp(q1, q2, p2);
        if (d1 >= 0) qs.push_back(p1); // p1 在刀切方向的左侧或线上，安全，保留
        if (d1 * d2 < 0) qs.push_back(isLL(p1, p2, q1, q2)); // 线段跨过刀身，求出交点加入多边形
    }
    return qs;
}

// ======================= 核心圆与三角形算法 =======================
// ⚠️ 警告：处理圆相关的，Type 开关 必须等于 double ！！！

// 1. 判断两圆关系
// 返回值: 4相离, 3外切, 2相交, 1内切, 0包含
int type(P o1, db r1, P o2, db r2) {
    db d = o1.distTo(o2);
    if (cmp(d, r1 + r2) == 1) return 4;
    if (cmp(d, r1 + r2) == 0) return 3;
    if (cmp(d, abs(r1 - r2)) == 1) return 2;
    if (cmp(d, abs(r1 - r2)) == 0) return 1;
    return 0;
}

// 2. 直线 p1-p2 与 圆(o,r) 的交点
// 沿着向量 p1->p2 方向排序返回。可能有 0、1、2 个点
vector<P> isCL(P o, db r, P p1, P p2) {
    if (cmp(abs((o - p1).det(p2 - p1) / p1.distTo(p2)), r) > 0) return {};
    db x = (p1 - o).dot(p2 - p1), y = (p2 - p1).abs2(), d = x * x - y * ((p1 - o).abs2() - r * r);
    d = max(d, (db)0.0);
    P m = p1 - (p2 - p1) * (x / y); // 垂足位置
    P dr = (p2 - p1) * (sqrt(d) / y); // 向两侧伸展的长度
    return {m - dr, m + dr};
}

// 3. 两圆交点
// 前提：确保两圆不完全重合！返回结果顺着 o1 的逆时针方向。可能返回 0、1、2 个点
vector<P> isCC(P o1, db r1, P o2, db r2) {
    db d = o1.distTo(o2);
    if (cmp(d, r1 + r2) == 1) return {};
    if (cmp(d, abs(r1 - r2)) == -1) return {};
    d = min(d, r1 + r2);
    db y = (r1 * r1 + d * d - r2 * r2) / (2 * d), x = sqrt(r1 * r1 - y * y);
    P dr = (o2 - o1).unit();
    P q1 = o1 + dr * y, q2 = dr.rot90() * x;
    return {q1 - q2, q1 + q2};
}

// 4. 求两圆公切线的切点
// 参数技巧：求外公切线传 r1-r2，内公切线传 r1+r2。如果求点到圆的切线直接让 r2 = 0。
// 返回 pair 的数组，代表 {圆1上的切点, 圆2上的切点}
vector<pair<P, P>> tanCC(P o1, db r1, P o2, db r2) {
    P d = o2 - o1;
    db dr = r1 - r2, d2 = d.abs2(), h2 = d2 - dr * dr;
    if (sign(d2) == 0 || sign(h2) < 0) return {};
    h2 = max(0.0, h2);
    vector<pair<P, P>> ret;
    for (db sign : {-1, 1}) {
        P v = (d * dr + d.rot90() * sqrt(h2) * sign) / d2;
        ret.push_back({o1 + v * r1, o2 + v * r2});
    }
    if (sign(h2) == 0) ret.pop_back();
    return ret;
}

// 辅助角：求向量夹角
db rad(P p1, P p2) {
    return atan2(p1.det(p2), p1.dot(p2));
}

// 5. 求圆与三角形的有向面积交
// 圆心必须在原点(0,0)，半径 r。三角形三个点为：原点，p1，p2。
// 神奇作用：用于求任意多边形和圆的相交面积。只要将多边形三角剖分后全丢进这个函数累加即可！
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

// 6. 三角形内心 (角平分线交点) - 构成的内切圆必定完全包裹在三角形内
P inCenter(P A, P B, P C) {
    double a = (B - C).abs(), b = (C - A).abs(), c = (A - B).abs();
    return (A * a + B * b + C * c) / (a + b + c);
}

// 7. 三角形外心 (中垂线交点) - 三点共圆的圆心
P circumCenter(P a, P b, P c) {
    P bb = b - a, cc = c - a;
    double db = bb.abs2(), dc = cc.abs2(), d = 2 * bb.det(cc);
    return a - P(bb.y * dc - cc.y * db, cc.x * db - bb.x * dc) / d;
}

// 8. 三角形垂心 (高线交点)
P othroCenter(P a, P b, P c) {
    P ba = b - a, ca = c - a, bc = b - c;
    double Y = ba.y * ca.y * bc.y;
    double A = ca.x * ba.y - ba.x * ca.y;
    double x0 = (Y + ca.x * ba.y * b.x - ba.x * ca.y * c.x) / A;
    double y0 = -ba.x * (x0 - c.x) / ba.y + ca.y;
    return {x0, y0};
}

// 9. 最小圆覆盖 (随机增量法，极简但极其好用)
// 作用：给定点集 ps，求能把所有点都装进去的最贴身的那个圆 {圆心, 半径}
// ⚠️ 警告：千万不要把第一行的 random_shuffle 给删了！那是保证 O(N) 复杂度的核心！
pair<P, db> min_circle(vector<P> ps) {
    random_shuffle(ps.begin(), ps.end());
    int n = ps.size();
    P o = ps[0];
    db r = 0;
    for (int i = 1; i < n; i++)
        if (o.distTo(ps[i]) > r + eps) { // ps[i] 在圈外了，必须拉进圈里
            o = ps[i], r = 0; // 以该点为新的暂定起手点
            for (int j = 0; j < i; j++)
                if (o.distTo(ps[j]) > r + eps) {
                    o = (ps[i] + ps[j]) / 2;
                    r = o.distTo(ps[i]); // 以 i,j 为直径构造圆
                    for (int k = 0; k < j; k++)
                        if (o.distTo(ps[k]) > r + eps) {
                            o = circumCenter(ps[i], ps[j], ps[k]); // i,j,k 三点共圆
                            r = o.distTo(ps[i]);
                        }
                }
        }
    return {o, r};
}