#include <bits/stdc++.h>
using namespace std;

int dfs(int u, int t, int flow, vector<vector<int>>& cap, vector<bool>& visited) {
    if (u == t) return flow;
    visited[u] = true;

    int n = cap.size();
    for (int v = 0; v < n; ++v) {
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
    vector<vector<int>> cap = {
        {0, 16, 13,  0,  0,  0},
        {0,  0,  0, 12,  0,  0},
        {0,  4,  0,  0, 14,  0},
        {0,  0,  9,  0,  0, 20},
        {0,  0,  0,  7,  0,  4},
        {0,  0,  0,  0,  0,  0}
    };
    int s = 0, t = 5;
    cout << fordFulkerson(cap, s, t) << '\n';
}