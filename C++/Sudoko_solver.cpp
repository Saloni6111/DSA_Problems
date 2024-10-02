/**
 * Problem: Sudoko Solver
 * Link: https://leetcode.com/problems/sudoku-solver/
 */

/**
 * Explaination:
 * The provided C++ code implements a backtracking algorithm to solve a Sudoku puzzle. Here’s a breakdown of its functions:
 *
 * Function isPossible:
 * This function checks if placing a character (ch) at position (r, c) on the board is valid.
 * It checks the entire row (r) and column (c) for the presence of ch.
 * It also checks the corresponding 3x3 subgrid to ensure ch is not already present.
 *
 * Function solve:
 * This is a recursive function that attempts to fill the Sudoku board.
 * It takes two parameters, r (current row) and c (current column).
 * If r is 9, it means the board is successfully filled, and it returns true.
 * If c is 9, it means the current row is filled, so it moves to the next row by calling itself with r + 1 and resetting c to 0.
 * If the current cell is not empty (i.e., contains a digit), it moves to the next column by calling itself with c + 1.
 * For empty cells (denoted by '.'), it tries every digit from '1' to '9':
 * If isPossible returns true for a digit, it places the digit in the cell, then recursively calls solve for the next column.
 * If placing the digit leads to a solution, it returns true. If not, it backtracks by resetting the cell to '.'.
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to check if placing character 'ch' at board[r][c] is valid or not
    bool isPossible(vector<vector<char>> &board, int r, int c, char ch)
    {
        // Check the entire row 'r' and column 'c' for the character 'ch'
        for (int i = 0; i < 9; i++)
        {
            if (board[r][i] == ch || board[i][c] == ch)
            {
                return false; // 'ch' is already in the same row or column
            }
        }

        // Determine the starting row and column of the 3x3 subgrid
        int row = (r / 3) * 3;
        int col = (c / 3) * 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[row + i][col + j] == ch)
                {
                    return false; // 'ch' is already in the subgrid
                }
            }
        }

        return true; // Placement is valid
    }

    // Recursive function to solve the Sudoku
    bool solve(vector<vector<char>> &board, int r = 0, int c = 0)
    {
        // If we have filled all rows, the Sudoku is solved
        if (r == 9)
        {
            return true; // Solved
        }

        // If we reach the end of a row, move to the next row
        if (c == 9)
        {
            return solve(board, r + 1, 0); // Move to the next row
        }

        // If the current cell is already filled, move to the next column
        if (board[r][c] != '.')
        {
            return solve(board, r, c + 1); // Skip filled cell
        }

        // Try placing digits '1' to '9' in the empty cell
        for (char ch = '1'; ch <= '9'; ch++)
        {
            // Check if placing 'ch' at board[r][c] is valid
            if (isPossible(board, r, c, ch))
            {
                board[r][c] = ch; // Place the number
                // Recursively attempt to fill the next cell
                if (solve(board, r, c + 1))
                {
                    return true; // Successfully solved
                }

                // If placing 'ch' didn't lead to a solution, backtrack
                board[r][c] = '.'; // Reset the cell for backtracking
            }
        }
        return false; // Trigger backtracking if no number fits
    }

public:
    // Public method to initiate the Sudoku solving process
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board); // Start solving the Sudoku
    }
};

int main()
{

    return 0;
}