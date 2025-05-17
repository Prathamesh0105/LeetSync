class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> digits;
        int factorial = 1;

        for (int i = 1; i < n; i++) {
            factorial *= i;
            digits.push_back(i);
        }
        digits.push_back(n);

        string result = "";
        k = k - 1;

        while (true) {
            int index = k / factorial;
            result += to_string(digits[index]);
            digits.erase(digits.begin() + index);

            if (digits.empty()) {
                break;
            }

            k = k % factorial;
            factorial /= digits.size();
        }

        return result;
    }
};
