
//optimal approach

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