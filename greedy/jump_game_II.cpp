#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int jumps = 0;

        if(n == 1) return 0;

        while(r < n - 1){
            int farthest = 0;

            for(int i = l; i <= r; i++){
                farthest = max(farthest, i + nums[i]);
            }

            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {2, 3, 1, 1, 4};

    int ans = obj.jump(nums);

    cout << "Minimum jumps = " << ans << endl;

    return 0;
}