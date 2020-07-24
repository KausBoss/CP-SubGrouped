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
	int ans=0;
	int func(TreeNode* root){
		//base case
		if(root==NULL){
			return 0;
		}
		//recursive case
		int left = func(root->left);
		int right= func(root->right);
		ans += abs(left) + abs(right);
		return root->val-1+left+right;
	}
    int distributeCoins(TreeNode* root) {
    	 func(root);
    	 return ans;
    }
};