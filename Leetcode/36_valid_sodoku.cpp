#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // bool isValidSudoku(vector<vector<char>>& board) {
    //     unordered_map<char, int> up_row;
    //     unordered_map<char, int> up_column;
    //     unordered_map<char, int> up_sub[9];

    //     for (int row = 0; row < 9; row++) {
    //     for (int col = 0; col < 9; col++) {
    //         if (board[row][col] != '.') {
    //             up_row[board[row][col]]++;
    //             if (up_row[board[row][col]] > 1)
    //                 return false;
    //         }

    //         if (board[col][row] != '.') {
    //             up_column[board[col][row]]++;
    //             if (up_column[board[col][row]] > 1)
    //                 return false;
    //         }

    //         int loc = (row/3 * 3 + col/3);
    //         if (board[row][col] != '.') {
    //             if (up_sub[loc].find(board[row][col]) != up_sub[loc].end())
    //                 return false;
    //             up_sub[loc][board[row][col]]++;
    //         }

    //     }
    //     up_row.clear();
    //     up_column.clear();
    //     }

    //     // unordered_map<char, int> up_sub;
    //     // for (int row = 0; row < 9; row += 3) {
    //     // for (int col = 0; col < 9; col += 3) {
    //     //     for (int i = row; i < row + 3; i++)
    //     //     for (int j = col; j < col + 3; j++) {
    //     //         if (board[i][j] != '.') {
    //     //             if (up_sub[board[i][j]] == 1)
    //     //                 return false;
    //     //             up_sub[board[i][j]]++;
    //     //         }
    //     //     }
    //     //     up_sub.clear();
    //     // }
    //     // }
    //     return true;
    // }


    // fastest way
    bool isValidSudoku(vector<vector<char>>& board) {
        constexpr int size = 9;
        unordered_set<char> s_row[size], s_col[size], s_sub[size];
    
        for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            char digit = board[row][col];
            if (digit == '.')
                continue;
            int loc = (row/3 * 3 + col/3);
            if (s_row[row].count(digit) || s_col[col].count(digit) || s_sub[loc].count(digit))
                return false;
            else {
                s_row[row].insert(digit);
                s_col[col].insert(digit);
                s_sub[loc].insert(digit);
            }
        }
        }
        return true;
    }
};

int main() {
    // vector<vector<char>> board = 
    vector<vector<char>> data = 
                                // {{'5','3','.','.','7','.','.','4','.'},
                                // {'6','.','.','1','9','5','.','.','.'},
                                // {'.','9','8','.','.','.','.','6','.'},
                                // {'8','.','.','.','6','.','.','.','3'},
                                // {'4','.','.','8','.','3','.','.','1'},
                                // {'7','.','.','.','2','.','.','.','6'},
                                // {'.','6','.','.','.','.','2','8','.'},
                                // {'.','.','.','4','1','9','.','.','5'},
                                // {'.','.','.','.','8','.','.','7','9'}};

                                {{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};
    Solution obj;
    obj.isValidSudoku(data);

    return 0;
}


    //     for (int i = 0; i < 9; i += 3) {
    //     for (int j = 0; j < 9; j += 3) {
    //         seen.clear();
    //         for (int k = i; k < i + 3; k++) {
    //             for (int l = j; l < j + 3; l++) {
    //                 char current = board[k][l];
    //                 if (current == '.') continue;
    //                 if (seen.find(current) != seen.end()) return false;
    //                 seen.insert(current);
    //             }
    //         }
    //     }


    //     for (int row = 0; row < 9; row++){
    //     for (int col = 0; col < 9; col++){
    //         int loc = (row / 3) * 3 + col / 3;
    //         if (board[row][col] != '.' && check_subbox[loc].find(board[row][col]) != check_subbox[loc].end()){
    //             return false;
    //         }
    //         check_subbox[loc].insert(board[row][col]);
    //     }
    // }
        // int sub_c = 3 * row + col % 3;
        //     int sub_r = 3 * row + inc;
        //     if (board[sub_r][sub_c] != '.') {
        //         up_sub[board[sub_r][sub_c]]++;
        //         if (up_sub[board[sub_r][sub_c]] > 1)
        //             return false;
        //     }