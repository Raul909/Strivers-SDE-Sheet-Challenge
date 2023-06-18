/*Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
*/

class Solution
{
    bool isSafe1(int row, int col, vector<string> board, int n)
    {
        // check for upper diagonal
        int duprow = row;
        int dupcol = col;

        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        // checking the left portion            // <----Q
        col = dupcol;
        row = duprow;

        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        // check for lower diagonal
        row = duprow;
        col = dupcol;

        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        // base condition
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe1(row, col, board, n)) // checks if the queen is safe to insert at that position
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        solve(0, board, ans, n);

        return ans;
    }
};
// this is tacking an extra space complexity for diagonal checks and the side checks over the recursive one
/*
Time Complexity: Exponential in nature, since we are trying out all ways. To be precise it goes as O

(N! * N) nearly.

Space Complexity: O(N^2)
*/

// optimized solution using hashmap function
class Solution
{
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
    {
        // base condition
        if (col == n) // if n = 4 the condition is met that means the queens have been succesfully placed
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + (col - row)] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + (col - row)] = 1; // checks the hash maps and the Q in the resp column and the row
                // now call the function
                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                // now remove the queen and the set hash maps for backtracking
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + (col - row)] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

        return ans;
    }
};

/*
Time Complexity: Exponential in nature since we are trying out all ways, to be precise it is O(N! * N).

Space Complexity: O(N)
*/