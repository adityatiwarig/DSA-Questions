// 🎯 Task

// Rearrange characters inside each row in alphabetical (ascending) order.

// After sorting all rows, check whether every column is also in alphabetical order (top → bottom).

// 👉 If all columns are sorted → return "YES"
// 👉 Otherwise → return "NO"

// ⚠️ You can rearrange characters only within the same row.
// You cannot move characters between rows.

//  grid = ["abc",
//          "ade",
//          "efg"]   -->[yes]



#include <bits/stdc++.h>
using namespace std;

string gridChallenge(vector<string> grid) {

    int n = grid.size();

    // Step 1: sort each row
    for(int i = 0; i < n; i++) {
        sort(grid[i].begin(), grid[i].end());
    }

    // Step 2: check columns
    for(int col = 0; col < n; col++) {
        for(int row = 0; row < n - 1; row++) {
            if(grid[row][col] > grid[row + 1][col])
                return "NO";
        }
    }

    return "YES";
}

int main() {

    int n;
    cin >> n;

    vector<string> grid(n);

    for(int i = 0; i < n; i++)
        cin >> grid[i];

    cout << gridChallenge(grid);

    return 0;
}