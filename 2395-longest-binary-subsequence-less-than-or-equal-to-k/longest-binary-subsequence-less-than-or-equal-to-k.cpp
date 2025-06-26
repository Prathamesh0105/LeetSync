class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int zeros = 0, ones = 0;
        long long value = 0, pow = 1;

        for (char c : s) {
            if (c == '0') zeros++;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                if (value + pow > k) {
                    continue;
                }
                value += pow;
                ones++;
            }
            pow <<= 1;
            if (pow > k) break; 
        }

        return zeros + ones;
    }
};