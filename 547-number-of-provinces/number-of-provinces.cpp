class Solution {
public:

    void dfs(vector<vector<int>>& isConnected, int city, vector<bool>& visited) {

        visited[city] = true;

        for (int next = 0; next < isConnected.size(); next++) {

            if (isConnected[city][next] == 1 && !visited[next]) {
                dfs(isConnected, next, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        int provinces = 0;

        vector<bool> visited(n, false);

        for (int city = 0; city < n; city++) {

            if (!visited[city]) {

                provinces++;

                dfs(isConnected, city, visited);
            }
        }

        return provinces;
    }
};