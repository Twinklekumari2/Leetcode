class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,string& s,
             vector<int>& last,vector<int>& newParent,
             vector<int>& parent){

        int ch = s[node]-'a';
        int prev = last[ch];

        if(prev != -1)
            newParent[node] = prev;
        else
            newParent[node] = parent[node];

        last[ch] = node;

        for(auto child : adj[node]){
            dfs(child,adj,s,last,newParent,parent);
        }

        last[ch] = prev;
    }

    int dfs2(int node,vector<vector<int>>& adj2,vector<int>& ans){

        ans[node] = 1;

        for(auto child : adj2[node]){
            ans[node] += dfs2(child,adj2,ans);
        }

        return ans[node];
    }

    vector<int> findSubtreeSizes(vector<int>& parent,string s){

        int n = parent.size();

        vector<vector<int>> adj(n);

        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26,-1);
        vector<int> newParent(n,-1);

        dfs(0,adj,s,last,newParent,parent);

        vector<vector<int>> adj2(n);

        for(int i=1;i<n;i++){
            adj2[newParent[i]].push_back(i);
        }

        vector<int> ans(n,0);

        dfs2(0,adj2,ans);

        return ans;
    }
};