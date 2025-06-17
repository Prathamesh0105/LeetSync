const int MOD = 1e9 + 7;

class Solution {
public:
    long long modInverse(long long a, long long mod){
        long long res = 1;
        long long power = mod - 2;

        while (power){
            if (power & 1)
                res = res * a % mod;
            a = a * a % mod;
            power >>= 1;
        }

        return res;
    }

    int nCr(int n, int r){
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;

        long long res = 1;

        for (int i = 1; i <= r; i++){
            res = res * (n - r + i) % MOD;
            res = res * modInverse(i, MOD) % MOD;
        }

        return (int)res;
    }


    long long bin_expo(long long a, long long b)
    {
        long long result = 1;
        while (b) {
            if (b & 1)
                result = (result * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }

    int countGoodArrays(int n, int m, int k) {
        // bin_expo = binary exponentiation = power a^b
        int formula = (m * 1ll * bin_expo(m-1, n-(k+1))) % MOD;

        int updated_formula = (formula *1ll* nCr(n-1, k)) % MOD; 

        return updated_formula;
    }
};