class Solution {
public:
    unordered_map<string, bool> memo;

    bool isScramble(string str1, string str2) {
        int len = str1.size();
        if (str2.size() != len)
            return false;
        if (str1 == str2)
            return true;
        if (len == 1)
            return false;

        string key = str1 + " " + str2;
        if (memo.find(key) != memo.end())
            return memo[key];

        for (int i = 1; i < len; i++) {
            bool noSwap = (
                isScramble(str1.substr(0, i), str2.substr(0, i)) &&
                isScramble(str1.substr(i), str2.substr(i))
            );

            if (noSwap)
                return true;

            bool swap = (
                isScramble(str1.substr(0, i), str2.substr(len - i)) &&
                isScramble(str1.substr(i), str2.substr(0, len - i))
            );

            if (swap)
                return true;
        }

        return memo[key] = false;
    }
};
