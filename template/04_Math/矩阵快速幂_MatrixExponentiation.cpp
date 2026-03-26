/*
 * 算法：矩阵加速 / 矩阵快速幂
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template<int N, i64 MOD = 998244353> struct Matrix {
    i64 mat[N][N];

    Matrix() {
        memset(mat, 0, sizeof(mat));
    }

    // 生成单位矩阵
    static Matrix identity() {
        Matrix res;
        for (int i = 0; i < N; i++) res.mat[i][i] = 1;
        return res;
    }

    Matrix operator*(const Matrix &B) const {
        Matrix res;
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                if (!mat[i][k]) continue; // 常数优化
                for (int j = 0; j < N; j++) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * B.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

template<int N, i64 MOD> Matrix<N, MOD> qpow(Matrix<N, MOD> A, i64 b) {
    Matrix<N, MOD> res = Matrix<N, MOD>::identity();
    while (b) {
        if (b & 1) res = res * A;
        A = A * A;
        b >>= 1;
    }
    return res;
}