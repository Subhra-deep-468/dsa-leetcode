class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& grid) {

        // Out of bounds
        if (i >= grid.size() || j >= grid[0].size()) {
            return INT_MAX;
        }

        // Destination reached
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j];
        }

        // Already computed
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = solve(i + 1, j, grid);
        int right = solve(i, j + 1, grid);

        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        dp.resize(rows, vector<int>(cols, -1));

        return solve(0, 0, grid);
    }
};