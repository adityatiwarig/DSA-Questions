
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;

        // left side part
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i = i + 1;
        }

        // merge overlapping intervals
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i = i + 1;
        }
        ans.push_back(newInterval);

        // remaining intervals
        while(i < n){
            ans.push_back(intervals[i]);
            i = i + 1;
        }

        return ans;
    }
};

int main() {


    vector<vector<int>> intervals = {
        {1,3},
        {6,9}
    };

    vector<int> newInterval = {2,5};

    Solution obj;
    vector<vector<int>> result = obj.insert(intervals, newInterval);

    
    cout << "Intervals after insertion:\n";
    for(auto &interval : result){
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}