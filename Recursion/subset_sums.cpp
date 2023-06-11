/*
Example 1:

Input: N = 3, arr[] = {5,2,1}

Output: 0,1,2,3,5,6,7,8

Explanation: We have to find all the subset’s sum and print them.
In this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8


Input: N=3,arr[]= {3,1,2}

Output: 0,1,2,3,3,4,5,6

Explanation: We have to find all the subset’s sum and print them.
In this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6
*/

// this is by my simple pick and not pick method of striver

class Solution
{
public:
    void printSum(int index, vector<int> &nums, vector<int> &temp, int sum, vector<int> &res)
    {
        if (index >= nums.size())
        {
            for (auto it : temp)
                sum += it;

            res.push_back(sum);

            return;
        }

        // pick condition
        temp.push_back(nums[index]);
        printSum(index + 1, nums, temp, sum, res);
        temp.pop_back();

        // not pick condition
        printSum(index + 1, nums, temp, sum, res);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> temp;
        vector<int> sum;
        printSum(0, arr, temp, 0, sum);

        sort(sum.begin(), sum.end());

        return sum;
    }
};



// striver's method

#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void subsetSumsHelper(int ind, vector<int> &arr, int n, vector<int> &ans, int sum)
    {
        if (ind == n)
        {
            ans.push_back(sum);
            return;
        }
        // element is picked
        subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
        // element is not picked
        subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans;
        subsetSumsHelper(0, arr, n, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    vector<int> arr{3, 1, 2};
    Solution ob;
    vector<int> ans = ob.subsetSums(arr, arr.size());
    sort(ans.begin(), ans.end()); //sorting will take extra time
    cout << "The sum of each subset is " << endl;
    for (auto sum : ans)
    {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}

/*Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it.
 So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.
*/