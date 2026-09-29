#include <bits/stdc++.h>
using namespace std;

void dfs(int start, const vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (visited[u]) continue;
        visited[u] = true;
        cout << u << ' ';
        for (int i = (int)adj[u].size() - 1; i >= 0; --i) {
            int v = adj[u][i];
            if (!visited[v]) st.push(v);
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    adj[0].push_back(1); adj[1].push_back(0);
    adj[0].push_back(2); adj[2].push_back(0);
    adj[1].push_back(3); adj[3].push_back(1);
    adj[1].push_back(4); adj[4].push_back(1);
    adj[2].push_back(5); adj[5].push_back(2);
    adj[4].push_back(5); adj[5].push_back(4);
    vector<bool> visited(n, false);
    dfs(0, adj, visited);
}