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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	if(!root){return {};}
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        vector<int>temp;
        while(!q.empty()){
        	auto r = q.front();
        	q.pop();
        	if(r == NULL){
        		ans.push_back(temp);
        		temp.clear();
        		if(!q.empty()){q.push(NULL);}
        	}
        	else{
        		temp.push_back(r->val);
        		if(r->left){q.push(r->left);}
        		if(r->right){q.push(r->right);}
        	}
        }
        for(int i=1; i<ans.size(); i+=2){
        	reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};