/*
 * 算法：扩展欧几里得 (exGCD)
 * 作用：求 ax + by = gcd(a, b) 的特解 (x, y)
 */
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// 求解 ax + by = c 的任意一组解
bool solve_equation(int a, int b, int c, int &x, int &y) {
    int d = exgcd(a, b, x, y);
    if (c % d != 0) return false; // 无解
    int k = c / d;
    x *= k;
    y *= k;
    return true;
}