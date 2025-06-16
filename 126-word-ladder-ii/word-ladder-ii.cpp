class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return {};

        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> levels;
        queue<string> q;
        q.push(beginWord);
        levels[beginWord] = 0;
        
        int level = 0;
        bool found = false;
        while (!q.empty() && !found) {
            int size = q.size();
            unordered_map<string, vector<string>> newParents;
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                string originalWord = word;
                for (int j = 0; j < word.size(); j++) {
                    char originalChar = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;
                        word[j] = c;
                        if (wordSet.find(word) != wordSet.end()) {
                            if (levels.find(word) == levels.end() || levels[word] == level + 1) {
                                if (levels.find(word) == levels.end()) {
                                    q.push(word);
                                    levels[word] = level + 1;
                                }
                                newParents[word].push_back(originalWord);
                            }
                        }
                    }
                    word[j] = originalChar;
                }
            }
            for (auto& p : newParents) {
                parents[p.first].insert(parents[p.first].end(), p.second.begin(), p.second.end());
            }
            level++;
        }

        vector<vector<string>> results;
        if (parents.find(endWord) == parents.end()) return results;

        vector<string> path;
        function<void(string)> dfs = [&](string word) {
            path.push_back(word);
            if (word == beginWord) {
                results.push_back(vector<string>(path.rbegin(), path.rend()));
            } else {
                for (const string& parent : parents[word]) {
                    dfs(parent);
                }
            }
            path.pop_back();
        };

        dfs(endWord);
        return results;
    }
};