#include<iostream>
#include <vector>
#include <algorithm>


using namespace std;

int maxDiff(int n , vector<int>&nums){
    sort(nums.begin(),nums.end());
    int k = n/2;

    if(n == 1) return nums[0];

    int s1 = 0;
    int s2 = 0;
    int j = 0;


    for(int i = 0;i<k;i++){
        nums[j] = nums[i];
        s1 +=nums[j];
        j++;

    }

    for(int i = k;i<n;i++){
        nums[j] = nums[i];
        s2 += nums[j];
        j++;
    }

    return s2 - s1;
    

}

int main(){
    int n ;

    cin>>n;
    vector<int>nums(n);
    

    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }

    cout<<maxDiff(n,nums);


}