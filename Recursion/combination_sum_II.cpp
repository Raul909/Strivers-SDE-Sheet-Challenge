/*
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/

class Solution
{
public:
    void comb_sum_II(int index, vector<int> &arr, int target, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (target == 0)
            ans.push_back(ds);

        for (int i = index; i < arr.size(); i++)
        {
            if (i > index && arr[i] == arr[i - 1])
                continue; // skips so that we don't pick up the same element in the same call and i>ind so that we can pick element after it even if is same in the next recursion call

            if (arr[i] > target)
                break; // break the loop if the elements in the array become greater than the target

            ds.push_back(arr[i]);
            comb_sum_II(i + 1, arr, target - arr[i], ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> ds;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end()); // sort the array for comparision not to pick the same element in the same recursion call more than once
        comb_sum_II(0, candidates, target, ds, res);

        return res;
    }
};