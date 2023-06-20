/*
Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
*/

class Solution
{
public:
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<vector<int>> &vis, vector<string> &ans, string move,
               int di[], int dj[])
    {
        // base condition
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";              // lexographical order
        for (int ind = 0; ind < 4; ind++) // for the 4 movements to make
        {
            int nexti = i + di[ind];                                                                              // for row movements down and up
            int nextj = j + dj[ind];                                                                              // for column movements left and right
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) // conditions for the rat to move
            {
                vis[i][j] = 1;                                                // visited check
                solve(nexti, nextj, a, n, vis, ans, move + dir[ind], di, dj); // goes for further recursion
                vis[i][j] = 0;                                                // not visit before backtracking
            }
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> res;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int di[] = {+1, 0, 0, -1}; // D->+1   U->-1
        int dj[] = {0, -1, 1, 0};  // R->+1   L->-1

        if (m[0][0] == 1)
            solve(0, 0, m, n, vis, res, "", di, dj);

        return res;
    }
};
