class Solution {
public:
    bool exist(vector<vector<char>>& grid, string target) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        unordered_set<string> visitedCells;

        auto search = [&](int row, int col, int index, auto& search) -> bool {
            if (index == target.length()) {
                return true;
            }

            if (row < 0 || row >= numRows || col < 0 || col >= numCols || 
                visitedCells.count(to_string(row) + "," + to_string(col)) || 
                grid[row][col] != target[index]) {
                return false;
            }

            visitedCells.insert(to_string(row) + "," + to_string(col));
            bool found = search(row + 1, col, index + 1, search) || 
                         search(row - 1, col, index + 1, search) || 
                         search(row, col + 1, index + 1, search) || 
                         search(row, col - 1, index + 1, search);
            visitedCells.erase(to_string(row) + "," + to_string(col));
            return found;
        };

        unordered_map<char, int> charCount;
        for (char ch : target) {
            charCount[ch]++;
        }

        if (charCount[target[0]] > charCount[target.back()]) {
            reverse(target.begin(), target.end());
        }

        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (search(row, col, 0, search)) {
                    return true;
                }
            }
        }

        return false;        
    }
};
