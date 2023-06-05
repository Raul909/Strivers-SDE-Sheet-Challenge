#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
    // Write your code here.
    unordered_map<int, int> mpp;

    for (auto it : arr)
    {
        mpp[it]++;
    }

    for (auto it : mpp)
    {
        if (it.second > 1)
            return it.first;
    }
    return 0;
}

// Time complexity --> O(n) , n being the number of elements in the vector

// Space complexity --> O(n)

// Floyd’s Tortoise and Hare Approach

#include <bits/stdc++.h>

using namespace std;
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
int main()
{
    vector<int> arr;
    arr = {1, 3, 4, 2, 3};
    cout << "The duplicate element is " << findDuplicate(arr) << endl;
}

// Time Complexity --> O(n)

// Space Complexity --> O(1)