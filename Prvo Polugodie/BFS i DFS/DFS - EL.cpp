#include <bits/stdc++.h>
using namespace std;

void dfs(int start, int n, const vector<pair<int, int>>& edges, vector<bool>& visited) {
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (visited[u]) continue;
        visited[u] = true;
        cout << u << ' ';
        for (int i = (int)edges.size() - 1; i >= 0; i--) {
            int a = edges[i].first;
            int b = edges[i].second;
            if (a == u && !visited[b]) st.push(b);
            if (b == u && !visited[a]) st.push(a);
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
    dfs(0, n, edges, visited);
}