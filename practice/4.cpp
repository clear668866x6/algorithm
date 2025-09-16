#include <bits/stdc++.h>
#include <fstream> // 包含文件流头文件
using namespace std;

#define N 500002
typedef long long db; // if long long, remember to use (__int128)
struct P {
    db x, y;
    P() {}
    constexpr P(const db &x, const db &y) : x(x), y(y) {}
};
typedef P vec;
inline constexpr P operator+(const P &a, const P &b) {
    return P(a.x + b.x, a.y + b.y);
}
inline constexpr P operator-(const P &a, const P &b) {
    return P(a.x - b.x, a.y - b.y);
}
inline constexpr P operator*(const db &a, const P &b) {
    return P(a * b.x, a * b.y);
}
inline constexpr P operator*(const P &a, const db &b) {
    return P(b * a.x, b * a.y);
}
inline constexpr P operator/(const P &a, const db &b) {
    return P(a.x / b, a.y / b);
}
inline constexpr bool operator==(const P &a, const P &b) {
    return a.x == b.x && a.y == b.y;
}
inline constexpr bool operator!=(const P &a, const P &b) {
    return a.x != b.x || a.y != b.y;
}
inline constexpr double abs(const P &x) {
    return sqrt(x.x * x.x + x.y * x.y);
}
inline constexpr db abs2(const P &x) {
    return x.x * x.x + x.y * x.y;
}
inline constexpr double dis(const P &a, const P &b) {
    // return abs(a-b);
    const db t1 = a.x - b.x, t2 = a.y - b.y;
    return sqrt(t1 * t1 + t2 * t2);
}
inline constexpr db operator*(const P &a, const P &b) {
    return a.x * b.x + a.y * b.y;
}
inline constexpr db operator^(const P &a, const P &b) {
    return a.x * b.y - a.y * b.x;
}
inline constexpr bool to_left(const P &a, const P &b) {
    return a.x * b.y > a.y * b.x;
} //(a^b)>0
inline constexpr bool to_right(const P &a, const P &b) {
    return a.x * b.y < a.y * b.x;
} //(a^b)<0
inline constexpr bool anglecmp(const P &a, const P &b) {
    if ((a.y >= 0) != (b.y >= 0)) return a.y >= 0;
    if ((a.x >= 0) != (b.x >= 0)) return (a.y >= 0) == (a.x >= 0);
    // return to_left(a,b);
    return a.x * b.y > b.x * a.y;
}
inline constexpr bool sameangle(const P &a, const P &b) {
    return (a.x >= 0) == (b.x >= 0) && (a.y >= 0) == (b.y >= 0) && a.x * b.y == a.y * b.x;
}
inline constexpr double cos(const P &a, const P &b) {
    // return a*b/(abs(a)*abs(b));
    return (a.x * b.x + a.y * b.y) / sqrt((a.x * a.x + a.y * a.y) * (b.x * b.x + b.y * b.y));
}
inline double S(const P &a, const P &b, const P &c) {
    // return abs((b-a)^(c-a))/2;
    return abs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)) / 2;
}
inline db S2(const P &a, const P &b, const P &c) {
    // return abs((b-a)^(c-a));
    return abs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}
inline constexpr P dir(const P &a) {
    // return a/abs(a);
    return a / sqrt(a.x * a.x + a.y * a.y);
}
struct L {
    P a, v;
    L() {}
    constexpr L(const P &a, const P &b) : a(a), v(b - a) {}
};
struct seg {
    P a, b;
    seg() {}
    constexpr seg(const P &a, const P &b) : a(a), b(b) {}
};
constexpr P inter(const L a, const L b) {
    //	a.a+t1a.v==b.a+t2b.v
    //	a.a.x+t1a.v.x==b.a.x+t2b.v.x;
    //	a.a.y+t1a.v.y==b.a.y+t2b.v.y;
    const db m = a.v.x * b.v.y - b.v.x * a.v.y;
    return P((b.a.x * a.v.x * b.v.y - a.a.x * b.v.x * a.v.y - a.v.x * b.v.x * (b.a.y - a.a.y)) / m,
             (a.v.x * b.v.y * a.a.y - b.v.x * a.v.y * b.a.y + (b.a.x - a.a.x) * a.v.y * b.v.y) / m);
}
inline constexpr bool on(const P &a, const L &b) {
    // return ((a-b.a)^b.v)==0;
    return (a.x - b.a.x) * b.v.y == (a.y - b.a.y) * b.v.x;
}
inline constexpr bool at_left(const P &a, const L &b) {
    // return ((a-b.a)^b.v)<0;
    return (a.x - b.a.x) * b.v.y < (a.y - b.a.y) * b.v.x;
}
inline constexpr bool at_right(const P &a, const L &b) {
    // return ((a-b.a)^b.v)>0;
    return (a.x - b.a.x) * b.v.y > (a.y - b.a.y) * b.v.x;
}
inline constexpr P rot(const P &x, const db angle) {
    const db c = cos(angle), s = sin(angle);
    return P(x.x * c - x.y * s, x.y * c + x.x * s);
}
inline constexpr P rot(const P &p, const P &d) {
    return P(p.x * d.x - p.y * d.y, p.x * d.y + p.y * d.x) / sqrt(d.x * d.x + d.y * d.y);
}
inline constexpr P drot(const P &p, const P &d) {
    return P(p.x * d.x - p.y * d.y, p.y * d.x + p.x * d.y);
}
inline double dis(const P &a, const L &b) {
    // return abs((b.a-a)^b.v)/abs(b.v);
    return abs((b.a.x - a.x) * b.v.y - (b.a.y - a.y) * b.v.x) / sqrt(b.v.x * b.v.x + b.v.y * b.v.y);
}
vector<P> convex(vector<P> a) {
    db mn = 9e18, m2 = 9e18;
    int p;
    for (int i = 0; i < a.size(); ++i)
        if (a[i].y < mn || (a[i].y == mn && a[i].x < m2)) mn = a[i].y, m2 = a[i].x, p = i;
    const P s = a[p];
    int h = 0;
    for (const P &i : a)
        if (i != s) a[h++] = i;
    a.resize(h);
    for (P &i : a) i = i - s;
    sort(a.begin(), a.end(), anglecmp);
    h = -1;
    for (const P &i : a)
        if (h >= 0 && sameangle(a[h], i)) {
            if (abs2(a[h]) < abs2(i)) a[h] = i;
        } else
            a[++h] = i;
    a.insert(a.begin(), P(0, 0));
    a.resize(h + 2);
    vector<P> st(h + 2);
    h = 0;
    for (const P &i : a) {
        while (h >= 2 && !to_left(st[h - 1] - st[h - 2], i - st[h - 1])) --h;
        st[h++] = i;
    }
    st.resize(h);
    for (P &i : st) i = i + s;
    return st;
}
bool in_convex(const P p, const vector<P> &a, const int m) // REQUIRES a={st,...,st}, m=lastid_maxy
{
    const int n = a.size(), x = p.x, y = p.y;
    if (y < a[0].y || y > a[m].y) return 0;
    if (a[1].y == a[0].y && y == a[0].y) return x >= a[0].x && x <= a[1].x;
    if (a[m].y == a[m - 1].y && y == a[m].y) return x >= a[m].x && x <= a[m - 1].x;
    int l = 0, r = m + 1;
    while (l != r - 1) {
        const int md = l + r >> 1;
        (a[md].y < y ? l : r) = md;
    }
    if (at_right(P(x, y), L(a[l], a[l + 1]))) return 0;
    l = m, r = n;
    while (l != r - 1) {
        const int md = l + r >> 1;
        (a[md].y > y ? l : r) = md;
    }
    if (at_right(P(x, y), L(a[l], a[l + 1]))) return 0;
    return 1;
}
int on_convex(const P p, const vector<P> &a, const int m) // REQUIRES a={st,...,st}, m=lastid_maxy
{
    const int n = a.size(), x = p.x, y = p.y;
    if (y < a[0].y || y > a[m].y) return -1;
    if (a[1].y == a[0].y && y == a[0].y) return x >= a[0].x && x <= a[1].x ? 0 : -1;
    if (a[m].y == a[m - 1].y && y == a[m].y) return x >= a[m].x && x <= a[m - 1].x ? m - 1 : -1;
    int l = 0, r = m + 1;
    while (l != r - 1) {
        const int md = l + r >> 1;
        (a[md].y < y ? l : r) = md;
    }
    if (on(P(x, y), L(a[l], a[l + 1]))) return l;
    l = m, r = n;
    while (l != r - 1) {
        const int md = l + r >> 1;
        (a[md].y > y ? l : r) = md;
    }
    if (on(P(x, y), L(a[l], a[l + 1]))) return l;
    return -1;
}
db half(vector<L> a) {
    static L q1[N << 1], *const q = q1 + N;
    static P p[N];
    sort(a.begin(), a.end(), [](const L &a, const L &b) { return anglecmp(a.v, b.v); });
    int h = -1;
    for (const L &i : a) {
        if (sameangle(a[h].v, i.v)) {
            if (at_right(a[h].a, i)) a[h] = i;
        } else
            a[++h] = i;
    }
    a.resize(h + 1);
    h = 0;
    int t = 1;
    for (const L &i : a) {
        while (h > t && at_right(inter(q[h], q[h - 1]), i)) --h;
        while (h > t && at_right(inter(q[t], q[t + 1]), i)) ++t;
        q[++h] = i;
    }
    while (h > t && at_right(inter(q[h], q[h - 1]), q[t])) --h;
    q[++h] = q[t];
    for (int i = 1; i <= h - t; ++i) p[i] = inter(q[t - 1 + i], q[t + i]);
    db s = 0;
    for (int i = 2; i < h - t; ++i) s += S(p[1], p[i], p[i + 1]);
    return s;
}
vector<pair<P, P>> spin(vector<P> con) {
    const int n = con.size();
    con.resize(n * 2);
    copy(con.begin(), con.begin() + n, con.begin() + n);
    vector<L> b(n);
    for (int i = 0; i < n; ++i) b[i] = L(con[i], con[i + 1]);
    const function<db(P, L)> d = [](const P &a, const L &b) { return abs((b.a - a) ^ b.v); };
    vector<pair<P, P>> s(n * 2);
    for (int l = 0, r = 1; l < n; ++l) {
        while (d(con[r], b[l]) < d(con[r + 1], b[l])) ++r;
        s[l * 2] = {con[l], con[r]};
        s[l * 2 + 1] = {con[l + 1], con[r]};
    }
    return s;
}
mt19937 eng;
template<typename _Tp1, typename _Tp2> inline _Tp2 rand(_Tp1 l, _Tp2 r) {
    uniform_int_distribution<_Tp2> dis(l, r);
    return dis(eng);
}
struct xx {
    int x, y, r;
    xx() {}
    constexpr xx(const int x, const int y, const int r) : x(x), y(y), r(r) {}
    inline constexpr bool operator&(const xx &b) const {
        const long long d = (long long)(x - b.x) * (x - b.x) + (long long)(y - b.y) * (y - b.y);
        return d >= (long long)(r - b.r) * (r - b.r) && d <= (long long)(r + b.r) * (r + b.r);
    }
};
struct xxx {
    int x, y;
    xxx() {}
    constexpr xxx(const int x, const int y) : x(x), y(y) {}
    inline constexpr bool operator&(const xx &b) const {
        return (long long)b.r * b.r == (long long)(b.x - x) * (b.x - x) + (long long)(b.y - y) * (b.y - y);
    }
};
constexpr int zy = 5;
vector<P> gen(const int n) {
    vector<P> a(n);
    for (P &i : a) i.x = rand(-zy, zy), i.y = rand(-zy, zy);
    const auto chk = [&]() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i != j)
                    for (int k = 0; k < n; ++k)
                        if (k != i && k != j && sameangle(a[i] - a[j], a[i] - a[k])) return 0;
        return 1;
    };
    while (!chk())
        for (P &i : a) i.x = rand(-zy, zy), i.y = rand(-zy, zy);
    return a;
}

int main() {
    // 创建一个输出文件流对象，并打开/创建 "output.txt" 文件
    ofstream outFile("output.txt");

    ios::sync_with_stdio(false);
    int seed = 0;
    eng = mt19937(++seed);
    int T = 10;

    // 将内容输出到 outFile，而不是 cout
    outFile << T << '\n';
    while (T--) {
        outFile << "200000 1000000000\n";
        outFile << "200000 ";
        for (int i = 199999; i; --i) {
            outFile << rand(1, 200000) << (i == 1 ? "\n" : " ");
        }
    }

    // 文件流对象在 main 函数结束时会自动关闭文件
    return 0;
}