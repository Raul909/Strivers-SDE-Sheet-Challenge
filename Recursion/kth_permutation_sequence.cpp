/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.



Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
*/

// brute force
class Solution
{
public:
    void perm(int ind, string nums, vector<string> &ans, int k)
    {
        // Base condition
        if (ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[ind], nums[i]);
            perm(ind + 1, nums, ans, k);
            swap(nums[ind], nums[i]);
        }
    }

    string getPermutation(int n, int k)
    {
        string nums;
        vector<string> res;

        for (int i = 1; i <= n; i++)
        {
            nums += to_string(i);
        }

        perm(0, nums, res, k);

        sort(res.begin(), res.end()); // sort the result to get the desired or kth permutation

        return res[k - 1];
    }
};
// this code will give TLE because of it's higher time complexity  , T.C --> O(n! x n) + O((n!)log(n!))

// So we need to optimize the solution

// optimal solution

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> numbers;
        int fact = 1;
        for (int i = 1; i < n; i++) // stores numbers from 1 to n - 1 in the vector numbers
        {
            fact = fact * i; // we will find the factorial upto n - 1 if 4! = 24 then 3! = 6 for our further convenience of calculation
            numbers.push_back(i);
        }
        numbers.push_back(n); // since we need to push the last number n
        string ans = "";
        k = k - 1; // for 0th based indexing to work properly
        while (true)
        {
            ans = ans + to_string(numbers[k / fact]);  // 16/6 = 2 that means the number 3 will be chosen if the arr = {1,2,3,4} 2nd index --> 3 + {1,2,4} push back 3 because it will be our first index in the 17th permutation
            numbers.erase(numbers.begin() + k / fact); // erase it from our numbers array --> {1,2,4}

            if (numbers.size() == 0) // that means the numbers is empty and we have reached our goal the kth permutation
            {
                break;
            }
            k = k % fact;                 // 16 % 6 = 4
            fact = fact / numbers.size(); // 6/3 --> 2 --> (6 permutations possible * 4 number starting with ) , fact = 2, (3* 2)
        }
        return ans;
    }
};