class Solution {
public:

    void dfs(int node, vector<vector<int>>& graph,
             vector<int>& path, vector<vector<int>>& ans) {

        // Put current node in path
        path.push_back(node);

        // If we reached the last node
        if (node == graph.size() - 1) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        // Go to every connected node
        for (int next : graph[node]) {
            dfs(next, graph, path, ans);
        }

        // Remove current node
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<vector<int>> ans;
        vector<int> path;

        dfs(0, graph, path, ans);

        return ans;
    }
};