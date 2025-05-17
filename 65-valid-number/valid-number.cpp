class Solution {
public:
    bool isNumber(string s) {
        int length = s.size();
        bool hasDecimal = false, hasDigit = false, hasExponent = false;

        for (int i = 0; i < length; i++) {
            if (isdigit(s[i])) {
                hasDigit = true;
            } 
            else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && (s[i - 1] != 'e' && s[i - 1] != 'E')) return false;
            } 
            else if (s[i] == 'e' || s[i] == 'E') {
                if (hasExponent || !hasDigit) return false;
                hasExponent = true;
                hasDigit = false;
            } 
            else if (s[i] == '.') {
                if (hasDecimal || hasExponent) return false;
                hasDecimal = true;
            } 
            else {
                return false;
            }
        }

        return hasDigit;
    }
};
