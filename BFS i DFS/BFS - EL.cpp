#include <bits/stdc++.h>
using namespace std;

void bfs(int start, const vector<pair<int, int>>& edges, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << ' ';
        for (auto [a, b] : edges) {
            if (a == u && !visited[b]) {
                visited[b] = true;
                q.push(b);
            }
            if (b == u && !visited[a]) {
                visited[a] = true;
                q.push(a);
            }
        }
    }
}

int main() {
    int n = 6;
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4},
        {2, 5},
        {4, 5}
    };
    vector<bool> visited(n, false);
    bfs(0, edges, visited);
}