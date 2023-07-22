
//for better understanding 

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> mergedIntervals;

        if(intervals.size() == 0) return mergedIntervals;

        //sort the intervals ds for convenience of calcualtion
        sort(intervals.begin(),intervals.end());

        //assigning a tempinterval variable for comparision
        vector<int> tempIntervals = intervals[0];

        for(auto it:intervals)
        {
            if(it[0]<=tempIntervals[1])
            {
                tempIntervals[1] = max(it[1],tempIntervals[1]); //stores the max of the last of the first and the first of the following element
            }
            else
            {
                mergedIntervals.push_back(tempIntervals);//pushes back that does not overlaps 
                tempIntervals = it;//reinitializes the tempInterval to the next upcoming row for the further comparisions to make
            }
        }
        mergedIntervals.push_back(tempIntervals);

        return mergedIntervals;


        
    }
};


//optimal apprach

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &arr)
    {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if (ans.empty() || arr[i][0] > ans.back()[1])
            {
                ans.push_back(arr[i]);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans;
    }
};