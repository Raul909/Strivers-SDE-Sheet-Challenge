class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        vector<int> res;
        int n = nums.size();
        int mm = floor(n/3) + 1;

        for(int i = 0 ; i < n ; i++)
        {
            mpp[nums[i]]++;

            if(mpp[nums[i]] == mm)
            res.push_back(nums[i]);
        }
        return res;
    }
};





// optimal approach (Moore's voting algorithm)

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int cnt1 = 0, cnt2 = 0;
        int el1, el2;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && nums[i] != el2)
            {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && nums[i] != el1)
            {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (el1 == nums[i])
                cnt1++;
            else if (el2 == nums[i])
                cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        int mm = floor(n / 3) + 1;
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (el1 == nums[i])
                cnt1++;

            if (el2 == nums[i])
                cnt2++;
        }
        vector<int> res;

        if (cnt1 >= mm)
            res.push_back(el1);

        if (cnt2 >= mm)
            res.push_back(el2);

        sort(res.begin(), res.end());

        return res;
    }
};