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
	vector<vector<int>> ans;
public:
	int Height(TreeNode* root){
		//base case
		if(root == NULL){
			return 0;
		}
		//recursive case
		return 1 + max(Height(root->left), Height(root->right));
	}
	void NthNodes(TreeNode* root, int n, int lev){
		//base case
		if(root == NULL){
			return;
		}
		if(n == 1){
			ans[lev].push_back(root->val);
		}
		//recursive case
		NthNodes(root->left, n-1, lev);
		NthNodes(root->right, n-1, lev);
		return;
	}

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h = Height(root);
        ans.resize(h+1);
        for(int i=1; i<=h; i++){
        	NthNodes(root, i, i);
        }
        reverse(ans.begin(), ans.end());
        ans.pop_back();
        return ans;
    }
};