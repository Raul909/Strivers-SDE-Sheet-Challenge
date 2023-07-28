// better solution for arrays with positive and zeroes and optimal solution for arrays with negative values (Hashing)

//T.C --> O(N * 1) or O(N * N)--> for worst collisions in unordered_map

//S.C -- > O(N)
#include <bits/stdc++.h>
int getLongestSubarray(vector<int> &nums, int k)
{

    int n = nums.size();

    unordered_map<long long, int> prefSumMap;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;
        if (prefSumMap.find(rem) != prefSumMap.end())
        {
            int len = i - prefSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // Store the cumulative sum and its index in the map
        if (prefSumMap.find(sum) == prefSumMap.end())
            prefSumMap[sum] = i;
    }

    return maxLen;
}




// optimal solution for arrays with positive and zeroes (two pointer approach)

//T.C --> O(2n)
//S.C --> O(1)

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    // Write your code here
    int n = a.size();

    int left = 0, right = 0;
    long long sum = a[0];

    int maxLen = 0;
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;

        if (right < n)
            sum += a[right];
    }
    return maxLen;
}