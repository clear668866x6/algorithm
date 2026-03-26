// 1. 数论分块 (计算 \sum_{i=1}^n floor(n / i))
// O(sqrt(n)) 复杂度
int SqrtDecomposition(int n) {
    int ans = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        int k = n / l;
        r = n / k; // r 是当前块的右边界
        // 这段区间 [l, r] 里的 n/i 的值全都是 k
        ans += (r - l + 1) * k;
    }
    return ans;
}

// 2. 快速位运算技巧 (求区间 [L, R] 内部元素的位运算极值)
namespace FastBitwise {
    // 快速求 [L, R] 的按位或 (OR) 的最大值
    int fast_or(int L, int R) {
        if (L == R) return L;
        int bit = 63 - __builtin_clzll(L ^ R);
        return L | ((1LL << (bit + 1)) - 1);
    }
    // 快速求 [L, R] 的按位与 (AND) 的最小值
    int fast_and(int L, int R) {
        if (L == R) return L;
        int bit = 63 - __builtin_clzll(L ^ R);
        return R & ~((1LL << (bit + 1)) - 1);
    }
} // namespace FastBitwise