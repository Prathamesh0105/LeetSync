using namespace std;
class Solution {
public:
    static int findKthNumber(int n, int K) {
        return solve(0, n, K);
    }

    static int solve(long long current, long long n, long long k) {
        if (k == 0)
            return (int)(current / 10);

        for (long long i = max(current, 1LL); i < current + 10; ++i) {
            long long count = numOfChildren(i, i + 1, n);
            if (count >= k)
                return solve(i * 10, n, k - 1);
            k -= count;
        }
        return -1;
    }

    static long long numOfChildren(long long current, long long neighbour, long long n) {
        if (neighbour > n) {
            if (current > n) return 0;
            return n - current + 1;
        }
        return neighbour - current + numOfChildren(current * 10, neighbour * 10, n);
    }
};