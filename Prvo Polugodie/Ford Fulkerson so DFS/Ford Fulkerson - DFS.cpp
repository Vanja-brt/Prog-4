#include <bits/stdc++.h>
using namespace std;

int dfs(int u, int t, int flow, vector<vector<int>>& cap, vector<bool>& visited) {
    if (u == t) return flow;
    visited[u] = true;

    int n = cap.size();
    for (int v = 0; v < n; v++) {
        if (!visited[v] && cap[u][v] > 0) {
            int pushed = dfs(v, t, min(flow, cap[u][v]), cap, visited);
            if (pushed > 0) {
                cap[u][v] -= pushed;
                cap[v][u] += pushed;
                return pushed;
            }
        }
    }
    return 0;
}

long long fordFulkerson(vector<vector<int>> cap, int s, int t) {
    int n = cap.size();
    long long maxFlow = 0;
    while (true) {
        vector<bool> visited(n, false);
        int pushed = dfs(s, t, INT_MAX, cap, visited);
        if (pushed == 0) break;
        maxFlow += pushed;
    }
    return maxFlow;
}

int main() {
    vector<vector<int>> cap1 = {
        {0, 8, 8,  0},
        {0,  0,  0, 8},
        {0,  1,  0,  8},
        {0,  0,  0,  0}
    };
    int s = 0, t = 3;
    cout << fordFulkerson(cap1, s, t) << '\n';
    vector<vector<int>> cap2 = {
        {0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    t=7;
    cout << fordFulkerson(cap2, s, t) << '\n';
    vector<vector<int>> cap3 = {
        {0, 10, 5, 15, 0, 0, 0, 0},
        {0, 0, 4, 0, 9, 15, 0, 0},
        {0, 0, 0, 4, 0, 8, 0, 0},
        {0, 0, 0, 0, 0, 0, 16, 0},
        {0, 0, 0, 0, 0, 15, 0, 10},
        {0, 0, 0, 0, 0, 0, 15, 10},
        {0, 0, 6, 0, 0, 0, 0, 10},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    cout << fordFulkerson(cap3, s, t) << '\n';
    vector<vector<int>> cap4 = {
        {0, 1, 3, 0, 0, 0},
        {0, 0, 0, 99, 99, 0},
        {0, 0, 0, 0, 99, 0},
        {0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0}
    };
    t=5;
    cout << fordFulkerson(cap4, s, t) << '\n';
}
