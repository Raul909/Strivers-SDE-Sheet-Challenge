// binary search  tree approach with T.C --> O(m + n)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();    // no of rows
        int n = matrix[0].size(); // no of columns

        int row = 0, col = n - 1;
        while (row <= m - 1 && col >= 0)
        {
            int curr = matrix[row][col];

            if (curr == target)
                return true;
            if (target > curr)
                row++;
            else
                col--;
        }
        return false;
    }
};

// optimal approach
//T.C --> O(log(m * n))
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();    // size of rows
        int n = matrix[0].size(); // size of cols

        int lo = 0;
        int hi = n * m - 1;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (matrix[mid / n][mid % n] == target)
                return true;

            if (matrix[mid / n][mid % n] < target)
                lo = mid + 1;

            else
                hi = mid - 1;
        }
        return false;
    }
};