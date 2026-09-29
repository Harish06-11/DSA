class Solution {
public:
    int m, n;
    
    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int idx) {
        
        // All characters matched
        if (idx == word.size())
            return true;
        
        // Out of bounds or wrong character
        if (r < 0 || r >= m || c < 0 || c >= n ||
            board[r][c] != word[idx])
            return false;
        
        // Mark cell as visited
        char temp = board[r][c];
        board[r][c] = '#';
        
        // Explore 4 directions
        bool found =
            dfs(board, word, r + 1, c, idx + 1) ||
            dfs(board, word, r - 1, c, idx + 1) ||
            dfs(board, word, r, c + 1, idx + 1) ||
            dfs(board, word, r, c - 1, idx + 1);
        
        // Backtrack
        board[r][c] = temp;
        
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == word[0]) {
                    if (dfs(board, word, r, c, 0))
                        return true;
                }
            }
        }
        
        return false;
    }
};
