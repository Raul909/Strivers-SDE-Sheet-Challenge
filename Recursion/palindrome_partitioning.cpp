/*
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]

*/

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path; // this will contain the individual substrings
        func(0, s, path, res);

        return res;
    }

    void func(int ind, string s, vector<string> &path, vector<vector<string>> &ans)
    {
        if (ind == s.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = ind; i < s.size(); ++i)
        {
            if (isPalindrome(s, ind, i))
            {
                path.push_back(s.substr(ind, i - ind + 1));
                func(i + 1, s, path, ans);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) // checking if the substring is palindrome or not
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};