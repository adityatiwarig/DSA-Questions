#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){

        
        sort(Arrival.begin(),Arrival.end());
        sort(Departure.begin(),Departure.end());

        int n = Arrival.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int maxi = 0;

        while(i < n){
            if(Arrival[i] < Departure[j]){
                cnt = cnt + 1;
                i = i + 1;
            }
            else{
                cnt = cnt - 1;
                j = j + 1;
            }

            maxi = max(cnt, maxi);
        }

        return maxi;
    }
};

int main() {

   
    vector<int> Arrival   = {900, 940, 950, 1100, 1500, 1800};
    vector<int> Departure = {910, 1200, 1120, 1130, 1900, 2000};

    Solution obj;
    int result = obj.findPlatform(Arrival, Departure);

    cout << "Minimum platforms required = " << result << endl;

    return 0;
}