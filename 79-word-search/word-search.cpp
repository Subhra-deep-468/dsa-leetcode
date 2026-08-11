class Solution {
public:

    bool solve(vector<vector<char>>& board, string& word,
               int row, int col, int index) {

        // We found the complete word
        if (index == word.size()) {
            return true;
        }

        // Out of bounds
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size()) {
            return false;
        }

        // Current character doesn't match
        if (board[row][col] != word[index]) {
            return false;
        }

        // Mark current cell as visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Try four directions
        bool found =
            solve(board, word, row + 1, col, index + 1) ||
            solve(board, word, row - 1, col, index + 1) ||
            solve(board, word, row, col + 1, index + 1) ||
            solve(board, word, row, col - 1, index + 1);

        // Backtrack: restore the cell
        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {

            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == word[0]) {

                    if (solve(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};