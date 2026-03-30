#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int z;
    cin >> z;
    vector<vector<char>> A(z + 1, vector<char>(z + 1, 0));
    for (int i = 1; i <= z; i++) {
        for (int j = 1; j <= z; j++) {
            cin >> A[i][j];
        }
    }

    int k;
    cin >> k;
    vector<int> K(k + 1, 0);
    for (int i = 1; i <= k; i++) cin >> K[i];

    int t = K[1];

    auto rotate = [&](int x, int y, int z, int rt) -> pair<int, int> {
        if (rt == 0) return {x, y};
        if (rt == 1) return {z - y + 1, x};
        if (rt == 2) return {z - x + 1, z - y + 1};
        return {y, z - x + 1};
    };

    int tot = 0;
    auto get = [&](int x, int y) {
        auto [nx, ny] = rotate(x, y, z, tot);
        return A[nx][ny];
    };

    while (t--) {
        array<int, 6> tmp;
        int del = 6, idx = 0;
        while (del--) {
            tmp[idx++] = K.back();
            K.pop_back();
        }

        if (tmp.back() == 1) {
            reverse(tmp.begin(), tmp.end());
            auto [op, u, v, l, d, r] = tmp;

            tot = (tot + r) % 4;

            vector<vector<char>> B(l + 2, vector<char>(l + 2, 0));
            for (int i = u; i <= u + l - 1; i++) {
                for (int j = v; j <= v + l - 1; j++) {
                    B[i - u + 1][j - v + 1] = get(i, j);
                }
            }

            d /= 90;

            vector<vector<char>> tmp2 = B;
            for (int i = 1; i <= l; i++) {
                for (int j = 1; j <= l; j++) {
                    auto [x, y] = rotate(i, j, l, 4 - d);
                    B[i][j] = tmp2[x][y];
                }
            }

            for (int i = u; i <= u + l - 1; i++) {
                for (int j = v; j <= v + l - 1; j++) {
                    auto [x, y] = rotate(i, j, z, tot);
                    A[x][y] = B[i - u + 1][j - v + 1];
                }
            }

        } else {
            reverse(tmp.begin(), tmp.end());
            auto [op, u, d, l, r, o] = tmp;
            vector<vector<char>> B(d - u + 2, vector<char>(r - l + 2, 0));
            for (int i = u; i <= d; i++) {
                for (int j = l; j <= r; j++) {
                    B[i - u + 1][j - l + 1] = get(i, j);
                }
            }
            if (o == -1) {
                for (int i = 1; i <= d - u + 1; i++) {
                    for (int j = 1; j <= (r - l + 1) / 2; j++) {
                        swap(B[i][j], B[i][(r - l + 1) - j + 1]);
                    }
                }
            } else {

                for (int j = 1; j <= (r - l + 1); j++) {
                    for (int i = 1; i <= (d - u + 1) / 2; i++) {
                        swap(B[i][j], B[(d - u + 1) - i + 1][j]);
                    }
                }
            }

            for (int i = u; i <= d; i++) {
                for (int j = l; j <= r; j++) {
                    auto [x, y] = rotate(i, j, z, tot);
                    A[x][y] = B[i - u + 1][j - l + 1];
                }
            }
        }
    }

    auto TA = A;
    for (int i = 1; i <= z; i++) {
        for (int j = 1; j <= z; j++) {
            TA[i][j] = get(i, j);
        }
    }

    A = TA;

    int l1 = 1, l2 = 1, r1 = z, r2 = z;

    for (int j = 1; j <= z; j++) {
        if (A[1][j] != '?') {
            l1 = j;
            break;
        }
    }
    for (int j = z; j >= 1; j--) {
        if (A[1][j] != '?') {
            r1 = j;
            break;
        }
    }

    for (int i = 1; i <= z; i++) {
        if (A[i][1] != '?') {
            l2 = i;
            break;
        }
    }

    for (int i = z; i >= 1; i--) {
        if (A[i][1] != '?') {
            r2 = i;
            break;
        }
    }

    int n = r2 - l2 + 1, m = r1 - l1 + 1;

    cout << n << ' ' << m << "\n";

    for (int i = l2; i <= r2; i++) {
        for (int j = l1; j <= r1; j++) {
            cout << A[i][j];
        }
        cout << "\n";
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