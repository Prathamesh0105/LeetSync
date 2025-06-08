using namespace std;

class Solution {
public:
    static vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= 9; ++i) {
            dfs(i, n, ans);
        }
        return ans;
    }

private:
    static void dfs(int cur, int n, vector<int>& ans) {
        if (cur > n) return;
        ans.push_back(cur);
        for (int d = 0; d <= 9; ++d) {
            int next = cur * 10 + d;
            if (next > n) break;
            dfs(next, n, ans);
        }
    }
};