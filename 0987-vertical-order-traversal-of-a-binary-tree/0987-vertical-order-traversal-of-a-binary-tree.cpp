/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; //vertical, level, value
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto front = q.front();
            q.pop();

            int level = front.second.first;
            int vertical = front.second.second;
            TreeNode* node = front.first;
            nodes[vertical][level].insert(node->val);
            if(node->left != nullptr){
                q.push({node->left, {level+1, vertical-1}});
            }
            if(node->right != nullptr){
                q.push({node->right, {level+1, vertical+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto& it : nodes){
            vector<int> col;
            for(auto& q : it.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;

    }
};