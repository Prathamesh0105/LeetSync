class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int key) {
        int rows = grid.size(), cols = grid[0].size();
        int r = 0, c = cols - 1; 

        while (r < rows && c >= 0) {
            if (grid[r][c] == key) return true;
            else if (grid[r][c] < key) r++; 
            else c--;
        }
        return false;
    }
};