/*
Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
*/

class Solution
{
public:
    void comb_sum(int index, int target, vector<int> &arr, vector<int> ds, vector<vector<int>> &res)
    {
        if (index >= arr.size())
        {
            if (target == 0)
                res.push_back(ds);

            return;
        }

        // pick the same elemental index condition
        if (arr[index] <= target)
        {

            ds.push_back(arr[index]);
            comb_sum(index, target - arr[index], arr, ds, res);
            ds.pop_back();
        }

        // move forward not picking up the same element in the same index
        comb_sum(index + 1, target, arr, ds, res);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> ds;
        vector<vector<int>> ans;

        comb_sum(0, target, candidates, ds, ans);

        return ans;
    }
};