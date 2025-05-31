class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> min_rolls(n * n + 1, -1);
        queue<int> q;
        min_rolls[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 1; i <= 6 && x + i <= n * n; i++) {
                int t = x + i, row = (t - 1) / n, col = (t - 1) % n;
                int v = board[n - 1 - row][row % 2 ? n - 1 - col : col];
                int y = v > 0 ? v : t; // follow ladder / snake if present
                if (y == n * n)
                    return min_rolls[x] + 1;
                if (min_rolls[y] == -1) {
                    min_rolls[y] = min_rolls[x] + 1;
                    q.push(y);
                }
            }
        }
        return -1;
    }
};