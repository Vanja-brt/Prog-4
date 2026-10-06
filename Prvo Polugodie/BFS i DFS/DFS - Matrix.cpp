#include <bits/stdc++.h>
using namespace std;

void dfs(int start, const vector<vector<int>>& mat, vector<bool>& visited) {
    int n = mat.size();
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (visited[u]) continue;
        visited[u] = true;
        cout << u << ' ';
        for (int v = n - 1; v >= 0; --v) {
            if (mat[u][v] == 1 && !visited[v]) st.push(v);
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
    dfs(0, mat, visited);
}