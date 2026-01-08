#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

int a, b, c, d;
double calc(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int sign(double x) {
    if (x > 0) return 1;
    return -1;
}

int main() {
    cin >> a >> b >> c >> d;

    double l = -100, r = 100;

    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (sign(calc(mid)) * sign(calc(mid + 1)) > 0) {
            l = mid;
        } else
            r = mid;
    }

    cout << r;
}