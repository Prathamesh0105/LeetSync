class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string result = "";
        queue<string> q;
        q.push("");
        while (!q.empty()) {
            string curr = q.front(); q.pop();
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                string next = curr + ch;
                if (isK(next, s, k)) {
                    result = next;
                    q.push(next);
                }
            }
        }
        return result;
    }

    bool isK(string sub, string t, int k) {
        int count = 0, i = 0;
        for (char ch : t) {
            if (ch == sub[i]) {
                if (++i == sub.size()) {
                    i = 0;
                    if (++count == k) return true;
                }
            }
        }
        return false;
    }
};