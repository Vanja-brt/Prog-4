#include <bits/stdc++.h>
using namespace std;

void bfs(int start, const vector<vector<int>>& mat, vector<bool>& visited) {
    int n = mat.size();
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << ' ';
        for (int v = 0; v < n; ++v) {
            if (mat[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0}
    };
    vector<bool> visited(mat.size(), false);
    bfs(0, mat, visited);
}