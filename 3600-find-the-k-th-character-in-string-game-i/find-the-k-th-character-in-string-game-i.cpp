class Solution {
public:
    char kthCharacter(int k) {
        std::string sb = "a";
        while (sb.length() < k) {
            int size = sb.length();
            for (int i = 0; i < size; ++i) {
                char nextChar = 'a' + ((sb[i] - 'a' + 1) % 26);
                sb += nextChar;
            }
        }
        return sb[k - 1];
    }
};