class Solution {
public:
    bool differByOneChar(string word1, string word2) {
        if (word1.length() != word2.length()) return false;
        int diffCount = 0;
        for (int i = 0; i < word1.length(); i++) 
            diffCount += word1[i] != word2[i];
        return diffCount == 1;
    }
    
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<int> dp(n, 1), parent(n, -1);
        int maxi = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] && 
                        differByOneChar(words[i], words[j]) && 
                            dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        
        vector<string> result;
        for (int i = 0; i < n; i++) {
            if (maxi == dp[i]) {
                while (i != -1) {
                    result.push_back(words[i]);
                    i = parent[i];
                }
                break;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};