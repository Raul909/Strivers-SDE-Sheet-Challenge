// this is my code to solve this or my first approach to the problem

#include <bits/stdc++.h>

void subset_II(int index, vector<int> &nums, vector<int> &ds, set<vector<int>> &ans)
{
    // base condition
    if (index >= nums.size())
    {
        // sort(ds.begin(),ds.end())
        ans.insert(ds);
        return;
    }

    // pick condition
    ds.push_back(nums[index]);
    subset_II(index + 1, nums, ds, ans);
    ds.pop_back();

    // not pick condition
    subset_II(index + 1, nums, ds, ans);
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<int> ds;
    set<vector<int>> st;

    sort(arr.begin(), arr.end());

    vector<vector<int>> res;

    subset_II(0, arr, ds, st);

    for (auto it : st)
        res.push_back(it);

    return res;
}

/*
Time Complexity: O( 2^n).
 2^n  for generating every subset and k* log( x)  to insert every combination of average length k in a set of size x.
 After this, we have to convert the set of combinations back into a list of list /vector of vectors which takes more time.

Space Complexity:  O(2^n * k) to store every subset of average length k.
 Since we are initially using a set to store the answer another O(2^n *k) is also used.
*/

// But we can optimize the above solution

// the optimal solution

#include <bits/stdc++.h>

using namespace std;
// void printAns(vector<vector<int>> &ans)
// {
//     cout << "The unique subsets are " << endl;
//     cout << "[ ";
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << "[ ";
//         for (int j = 0; j < ans[i].size(); j++)
//             cout << ans[i][j] << " ";
//         cout << "]";
//     }
//     cout << " ]";
// }
class Solution
{
private:
    void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
    {
        ans.push_back(ds);
        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind && nums[i] == nums[i - 1])
                continue;
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ds, ans);
        return ans;
    }
};
// int main()
// {
//     Solution obj;
//     vector<int> nums = {1, 2, 2};
//     vector<vector<int>> ans = obj.subsetsWithDup(nums);
//     printAns(ans);
//     return 0;
// }

/*
Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in
 another data structure if the average length of every subset is k. Overall O(k * 2^n).

Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)
 if n is the depth of the recursion tree.
 */