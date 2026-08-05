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
        queue<tuple<TreeNode*,int,int>> qu;
        map<int,vector<pair<int,int>>> mp;

        qu.push(make_tuple(root,0,0));
        mp[0].push_back({0,root->val});
        while(!qu.empty()){
            auto front=qu.front();
            qu.pop();
            TreeNode* root=get<0>(front);
            int row=get<1>(front);
            int col=get<2>(front);

            if(root->left!=NULL) {
                qu.push(make_tuple(root->left,row+1,col-1));
                mp[col-1].push_back(make_pair(row+1,root->left->val));
            }
            if(root->right!=NULL){
                qu.push(make_tuple(root->right,row+1,col+1));
                mp[col+1].push_back(make_pair(row+1,root->right->val));
            } 
        }

        vector<vector<int>> res;
        for (auto &node : mp) {
        sort(node.second.begin(), node.second.end()); 

        vector<int> cur;
        for (auto &x : node.second)
            cur.push_back(x.second);
            res.push_back(cur);
        }
        return res;
    }
};