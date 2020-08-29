/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> ans;
	void permute(TreeNode *root, int k){
		//base case
		if(root==NULL){
			return;
		}
		if(k == 0){
			ans.push_back(root->val);
			return;
		}
		//recursive case
		permute(root->left, k-1);
		permute(root->right, k-1);
		return;
	}
	int helper(TreeNode* root, TreeNode* k, int d){
		//base case
		if(root==NULL){return -1;}
		//recursive case
		int left = helper(root->left, k, d);
		int right = helper(root->right, k, d);
		if(root == k){
			permute(root, d);
			return 1;
		}
		if(d==left || d==right){
			permute(root, 0);
			return -1;
		}
		if(left != -1){
			permute(root->right, d-1-left);
			return left+1;
		}
		if(right != -1){
			permute(root->left, d-1-right);
			return right+1;
		}
		return -1;
	}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int d) {
        helper(root, target, d);
        return ans;
    }
};