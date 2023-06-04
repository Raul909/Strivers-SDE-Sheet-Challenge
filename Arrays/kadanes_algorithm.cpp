#include <bits/stdc++.h>

// Time complexity --> O(n^2)
long long maxSubarraySum(int arr[], int n)
{

    long long best = 0;

    for (int k = a; a < n; a++)
    {
        long long sum = 0;
        for (int b = a; b < n; b++)
        {
            sum += (long long)arr[b];
            best = max(best, sum);
        }
        return best;
    }
}

// Optimizing the above approach
// We can rewrite using a single for loop

// Time complexity --> O(n^2)

long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0;
    long long best = 0;

    for (int k = 0; k < n; k++)
    {
        sum = max((long long)(arr[k]), sum + (long long)(arr[k]));
        best = max(best, sum);
    }
    return best;
}
