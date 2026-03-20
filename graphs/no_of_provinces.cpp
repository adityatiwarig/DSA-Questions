#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adjL, vector<int>& vis) {
    vis[node] = 1;

    for (int it : adjL[node]) {
        if (!vis[it]) {
            dfs(it, adjL, vis);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {

    int V = isConnected.size();
    vector<vector<int>> adjL(V);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (isConnected[i][j] == 1 && i != j) {
                adjL[i].push_back(j);
            }
        }
    }

    vector<int> vis(V, 0);
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            count++;
            dfs(i, adjL, vis);
        }
    }

    return count;
}

int main() {


    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    // Direct function call
    int ans = findCircleNum(isConnected);

    cout << "Number of Provinces: " << ans << endl;

    return 0;
}