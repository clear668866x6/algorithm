#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define int int64_t
#define double long double
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
    double tsx, tsy, tgx, tgy;
    double asx, asy, agx, agy;
    cin >> tsx >> tsy >> tgx >> tgy >> asx >> asy >> agx >> agy;

    auto dist = [&](double x1, double y1, double x2, double y2) {
        double dx = x1 - x2;
        double dy = y1 - y2;
        return sqrt(dx * dx + dy * dy);
    };

    double d1 = dist(tsx, tsy, tgx, tgy);
    double d2 = dist(asx, asy, agx, agy);
    double ans = 1e18;

    if (d1 < 1e-12 && d2 < 1e-12) {
        ans = min(ans, dist(tgx, tgy, agx, agy));
        cout << fixed << setprecision(16) << ans << endl;
        RE;
    }

    double v1x = (tgx - tsx) / d1;
    double v1y = (tgy - tsy) / d1;
    double v2x = (agx - asx) / d2;
    double v2y = (agy - asy) / d2;

    double A = (tsx - asx);
    double B = (v1x - v2x);
    double C = (tsy - asy);
    double D = (v1y - v2y);

    //[0,min(d1,d2)]

    double a = B * B + D * D;
    double b = 2 * (A * B + C * D);
    double c = (A * A + C * C);

    double t1 = min(d1, d2);

    if (a > 1e-12) {
        double t0 = -b / (2 * a);
        if (t0 >= 0 && t0 <= t1) {
            ans = min(ans, sqrt(a * t0 * t0 + b * t0 + c));
        }
    }

    ans = min({ans, sqrt(c), sqrt(a * t1 * t1 + b * t1 + c)});

    // 到达
    if (d1 < d2) {
        // t dao
        A = (asx - tgx);
        B = v2x;
        C = (asy - tgy);
        D = v2y;

        a = B * B + D * D;
        b = 2 * (A * B + C * D);
        c = (A * A + C * C);

        if (a > 1e-12) {
            double t0 = -b / (2 * a);
            if (t0 >= d1 && t0 <= d2) {
                ans = min(ans, sqrt(a * t0 * t0 + b * t0 + c));
            }
        }

        ans = min({ans, sqrt(a * d2 * d2 + b * d2 + c), sqrt(a * d1 * d1 + b * d1 + c)});
    } else {
        A = (tsx - agx);
        B = v1x;
        C = (tsy - agy);
        D = v1y;

        a = B * B + D * D;
        b = 2 * (A * B + C * D);
        c = (A * A + C * C);

        if (a > 1e-12) {
            double t0 = -b / (2 * a);
            if (t0 >= d2 && t0 <= d1) {
                ans = min(ans, sqrt(a * t0 * t0 + b * t0 + c));
            }
        }

        ans = min({ans, sqrt(a * d2 * d2 + b * d2 + c), sqrt(a * d1 * d1 + b * d1 + c)});
    }

    ans = min(ans, dist(tgx, tgy, agx, agy));

    cout << fixed << setprecision(16) << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}
