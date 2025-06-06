class Solution {
public:
    // Helper function to find the lexicographically smallest remaining character
    char l(vector<int>& freq) {
        for (int i = 0; i < 26; i++) {
            if (freq[i]) return 'a' + i;
        }
        return 'a';
    }

    string robotWithString(string s) {
        stack<char> st;
        string t = "";
        vector<int> freq(26);

        // Count frequency of each character in s
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Iterate over characters in s
        for (char ch : s) {
            st.push(ch);
            freq[ch - 'a']--;

            // Pop from stack to result if stack top ≤ smallest remaining char
            while (!st.empty() && st.top() <= l(freq)) {
                t += st.top();
                st.pop();
            }
        }

        // Pop remaining characters
        while (!st.empty()) {
            t += st.top();
            st.pop();
        }

        return t;
    }
};