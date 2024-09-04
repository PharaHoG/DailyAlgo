// 方法一
class Solution {
public:
    void findBlank(const vector<vector<char>>& board, int* row, int* col) {
        // 从给定 row col 开始查找下一个 blank 坐标
        for (int i = *row; i < 9; i++) {
            for (int j = *col; j < 9; j++) {
                if (board[i][j] == '.') {
                    *row = i;
                    *col = j;
                    return;
                } else {
                    if (j == 8) {
                        if (i == 8) {
                            *row = 8;
                            *col = 9;
                        } else {
                            j = -1;
                            i++;
                        }
                    }
                }
            }
        }
        *row = 8;
        *col = 9;
    }

    bool isValid(const vector<vector<char>>& board, int num, int row, int col) {
        // 检查 num 是否可放在 board 的 row 行，col 列上
        // 检查 row 与 col
        for (int i = 0; i < 9; i++) {   
            if (board[i][col] == num + '0' || board[row][i] == num + '0') {
                return false;
            }
        }
        // 检查3x3宫内
        int sr = row - row % 3;
        int sl = col - col % 3;
        for (int i = sr; i < sr + 3; i++) {
            for (int j = sl; j < sl + 3; j++) {
                if (board[i][j] == num + '0') {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(vector<vector<char>>& board, int row, int col) {
        findBlank(board, &row, &col);
        if (row == 8 && col == 9) {
            return true;
        }
        for (int i = 1; i <= 9; i++) {
            if (isValid(board, i, row, col)) {
                board[row][col] = '0' + i;
                if (dfs(board, row, col)) {
                    return true;
                    cout << "was here";
                }
                board[row][col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, row, col);
    }
};

// 方法二
// 在循环中跳过非空格
class Solution {
public:
    bool isValid(const vector<vector<char>>& board, int num, int row, int col) {
        // 检查 num 是否可放在 board 的 row 行，col 列上
        // 检查 row 与 col
        for (int i = 0; i < 9; i++) {   
            if (board[i][col] == num + '0' || board[row][i] == num + '0') {
                return false;
            }
        }
        // 检查3x3宫内
        int sr = row - row % 3;
        int sl = col - col % 3;
        for (int i = sr; i < sr + 3; i++) {
            for (int j = sl; j < sl + 3; j++) {
                if (board[i][j] == num + '0') {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.')
                    continue;
                for (int k = 1; k <= 9; k++) {
                    if (isValid(board, k, i, j)) {
                        board[i][j] = k + '0';
                        if (dfs(board))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
};