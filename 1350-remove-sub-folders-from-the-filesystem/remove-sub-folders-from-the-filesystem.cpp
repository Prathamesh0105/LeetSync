class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> dirSet(folder.begin(), folder.end());
        vector<string> res;
        for (const string& dir : folder) {
            res.push_back(dir);
            for (int i = 0; i < dir.size(); ++i) {
                if (dir[i] == '/' && dirSet.count(dir.substr(0, i))) {
                    res.pop_back();
                    break;
                }
            }
        }
        
        return res;
    }
};