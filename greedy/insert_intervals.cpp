#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;

        // left side (no overlap)
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        // merge overlapping intervals
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        ans.push_back(newInterval);

        // remaining intervals
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> intervals = {
        {1,3},
        {6,9}
    };

    vector<int> newInterval = {2,5};

    vector<vector<int>> result = obj.insert(intervals, newInterval);

    cout << "Result intervals:\n";
    for(auto &v : result){
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    return 0;
}