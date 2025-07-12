#include <iostream>
#include <cmath>
#include <algorithm> // For std::max

long long N;
long long MOD = 998244353;

// Function to compute (base^exp) % mod using binary exponentiation
long long power (long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Function to compute modular inverse using Fermat's Little Theorem (MOD is prime)
long long modInverse (long long n) {
    return power (n, MOD - 2);
}

int main () {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio (false);
    std::cin.tie (NULL);

    std::cin >> N;

    // Precompute modular inverse of 2
    long long inv2 = modInverse (2);

    long long total_count = 0;
    // Determine the split point for square root decomposition
    long long B = sqrt (N);

    // Part 1: Summation for b from 2 up to B
    // Calculate f(N, b) = r*q + (b-1-r)*(q-1) for each b
    for (long long b = 2; b <= B; ++b) {
        long long q = N / b;
        long long r = N % b;

        // Contribution from terms where floor is q: r * q
        long long term1 = (r % MOD * (q % MOD)) % MOD;

        // Contribution from terms where floor is q-1: (b-1-r) * (q-1)
        // Number of terms where floor is q-1
        long long num_terms_q_minus_1 = (b - 1 - r + MOD) % MOD;
        // Contribution, ensuring (q-1) is handled correctly modulo MOD
        long long term2 = (num_terms_q_minus_1 * (q - 1 + MOD)) % MOD;

        // f(N, b) modulo MOD
        long long current_f_N_b = (term1 + term2) % MOD;
        // Add to the total count
        total_count = (total_count + current_f_N_b) % MOD;
    }

    // Part 2: Summation for b from B+1 up to N
    // This part iterates over possible values of q = floor(N/b)
    // q ranges from 1 up to floor(N / (B+1))
    long long max_q = (B == 0) ? N : N / (B + 1); // Handle potential edge case if B=0 (though N>=3)

    for (long long q = 1; q <= max_q; ++q) {
        // For a fixed q, the range of b such that floor(N/b) = q is:
        // floor(N/(q+1)) + 1 <= b <= floor(N/q)
        long long b_low_bound_for_q = N / (q + 1);
        long long b_high_bound_for_q = N / q;

        // We are interested in b values within [B+1, N] that also satisfy floor(N/b)=q
        // So, the effective range for b is [max(B+1, b_low_bound_for_q + 1), b_high_bound_for_q]
        long long b_start = std::max (B + 1, b_low_bound_for_q + 1);
        long long b_end = b_high_bound_for_q;

        // If the range for b is invalid (start > end), skip this q
        if (b_start > b_end) {
            continue;
        }

        // K is the number of b values in the current valid range [b_start, b_end]
        long long K = b_end - b_start + 1;

        // We need to sum f(N, b) = N - b - q + 1 for b in [b_start, b_end]
        // Sum = sum_{b=b_start}^{b_end} (N - q + 1) - sum_{b=b_start}^{b_end} b

        // Calculate sum of (N - q + 1) for K terms: K * (N - q + 1) mod MOD
        // (N - q + 1) mod MOD
        long long term_const = (N % MOD - q % MOD + 1 + MOD) % MOD;
        // K * (N - q + 1) mod MOD
        long long sum_N_q_1 = (K % MOD * term_const) % MOD;

        // Calculate sum of b from b_start to b_end: K * (b_start + b_end) / 2 (mod MOD)
        // (b_start + b_end) mod MOD
        long long b_start_mod = b_start % MOD;
        long long b_end_mod = b_end % MOD;
        // K * (b_start + b_end) mod MOD
        long long sum_b_values_num = (K % MOD * ((b_start_mod + b_end_mod) % MOD)) % MOD;
        // (K * (b_start + b_end) / 2) mod MOD
        long long sum_b_values = (sum_b_values_num * inv2) % MOD;

        // Contribution for this q: (sum of (N - q + 1)) - (sum of b) (mod MOD)
        long long sum_part2_for_q = (sum_N_q_1 - sum_b_values + MOD) % MOD;

        // Add this contribution to the total count
        total_count = (total_count + sum_part2_for_q) % MOD;
    }

    std::cout << total_count << std::endl;

    return 0;
}