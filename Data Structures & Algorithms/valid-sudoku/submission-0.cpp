int getSquare(int x, int y);

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> squares(9);

        // hash rows / cols / squares
        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                char target = board[y][x];
                if (target == '.') continue;

                if (rows[x].count(target)) {
                    return false;
                }

                if (cols[y].count(target)) {
                    return false;
                }

                int square = getSquare(x, y);
                if (squares[square].count(target)) {
                    return false;
                }

                rows[x].insert(target);
                cols[y].insert(target);
                squares[square].insert(target);
            }
        }

        return true;
    }
};

// indexed squares left to right, top to bottom 0 - 8
int getSquare(int x, int y) {
    return (3 * floor(y / 3) + (floor(x / 3)));
}
