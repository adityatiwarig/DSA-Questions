// DATE 19 MARCH 2026

// Marc’s Cakewalk — Problem Statement (Short & Easy Revision Version)

// Marc loves cupcakes. Each cupcake has a calorie value.

// After eating cupcakes, Marc must walk to burn calories.

// If Marc eats cupcakes in some order, the total miles he must walk is:

//(2^0 * 10) + (2^1 * 7) + (2^2 * 5)
// = 10 + 14 + 20
// = 44

// n = 3
// calorie = [5, 10, 7]



#include <bits/stdc++.h>
using namespace std;


long marcsCakewalk(vector<int> calorie) {
    sort(calorie.begin(), calorie.end());

    long long sum = 0;
    int ind = 0;

    for(int i = calorie.size()-1; i >= 0; i--) {
        sum += (long long)pow(2, ind) * calorie[i];
        ind++;
    }

    return sum;
}

int main() {

    int n;
    cin >> n;                 // number of cupcakes

    vector<int> calorie(n);

    for(int i = 0; i < n; i++)
        cin >> calorie[i];    // calories input

    long result = marcsCakewalk(calorie);

    cout << result << endl;

    return 0;
}