

// better approach

#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    vector<int> hash(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    int repeating = -1;
    int missing = -1;
    for (int i = 1; i < n + 1; i++)
    {
        if (hash[i] == 0)
            missing = i;

        if (hash[i] >= 2)
            repeating = i;

        if (repeating != -1 && missing != -1)
            break;
    }

    pair<int, int> res;

    res.first = missing;
    res.second = repeating;

    return res;
}

// optimal approach

#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    // sn = (n * (n + 1))/2

    long long sn = (n * (n + 1)) / 2;

    // s2n = (n * (n + 1) * (2 * n + 1))/6

    long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;

    long long s = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];

        s2 += (long long)arr[i] * (long long)arr[i];
    }

    // sn - s
    long long val1 = sn - s;

    long long val2 = s2n - s2;

    val2 = val2 / val1;

    long long missing = (val1 + val2) / 2;
    long long repeating = val2 - missing;

    pair<int, int> res;

    res.first = missing;
    res.second = repeating;

    return res;
}
