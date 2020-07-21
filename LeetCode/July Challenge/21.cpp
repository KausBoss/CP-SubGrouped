class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if (search(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    
    bool search(vector<vector<char>>& board, string word, int i, int j, int pos) {
        
        if (pos == word.size()) return true;
        if ((i<0) || (i >= board.size()) || (j <0) || (j >= board[i].size())) return false;
        char c = board[i][j];
        if (c == word[pos]) {
            board[i][j] = '#';
            if (search(board, word, i - 1, j, pos + 1)) return true;
            if (search(board, word, i+1, j, pos+1)) return true;
            if (search(board, word, i, j-1, pos+1)) return true;
            if (search(board, word, i, j+1, pos+1)) return true;
            board[i][j] = c;
        }
        return false;
        
    }
};