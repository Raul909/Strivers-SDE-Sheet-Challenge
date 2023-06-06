class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (mpp.find(target - nums[i]) != mpp.end()) // we check if target-arr[i] does it exist in the hash table or not if it does it will never point to the end of the hash table
            {
                ans.push_back(mpp[target - nums[i]]);
                ans.push_back(i);
                return ans; // exactly one solution and it will execute since it will return the ans and it will not run again
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }
};