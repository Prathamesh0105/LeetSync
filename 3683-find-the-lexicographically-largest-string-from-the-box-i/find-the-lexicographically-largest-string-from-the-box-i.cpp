class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        string res = "";
        for (int i = 0 ; i < word.size() ; i++) 
            res = max(res, word.substr(i, word.length() - numFriends + 1));
        return res;
    }
};