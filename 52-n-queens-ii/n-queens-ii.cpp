class Solution {
private:
    int count = 0;

public:
    int totalNQueens(int n) {
        count = 0;
        backtrack(0, n, 0, 0, 0);
        return count;
    }

    void backtrack(int row, int n, unsigned long long columns, unsigned long long diag1, unsigned long long diag2) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            unsigned long long curr_col = 1ULL << col;
            unsigned long long curr_diag1 = 1ULL << (row - col + n - 1);
            unsigned long long curr_diag2 = 1ULL << (row + col);

            if ((columns & curr_col) || (diag1 & curr_diag1) || (diag2 & curr_diag2)) {
                continue;
            }

            backtrack(row + 1, n, columns | curr_col, diag1 | curr_diag1, diag2 | curr_diag2);
        }
    }
};