//  19 march dsa 3

//  ✅ Luck Balance — Short Question (Revision Version)

// Lena participates in n contests.

// Each contest has two values:

// L → luck value

// T → importance

// T = 1 → important

// T = 0 → unimportant

// Rules:

// If Lena loses a contest → luck +L

// If she wins → luck −L

// She can lose at most k important contests.

// 👉 Find the maximum luck balance she can achieve.



#include <bits/stdc++.h>
using namespace std;

int luckBalance(int k, vector<vector<int>> contests) {
    int luck = 0;
    vector<int> important;

    // separate contests
    for(auto &c : contests) {
        int L = c[0];
        int T = c[1];

        if(T == 0)
            luck += L;          // lose all unimportant
        else
            important.push_back(L);
    }

    // sort important contests (descending)
    sort(important.begin(), important.end(), greater<int>());

    // lose k important, win rest
    for(int i = 0; i < important.size(); i++) {
        if(i < k)
            luck += important[i];
        else
            luck -= important[i];
    }

    return luck;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> contests(n, vector<int>(2));

    for(int i = 0; i < n; i++)
        cin >> contests[i][0] >> contests[i][1];

    cout << luckBalance(k, contests);

    return 0;
}