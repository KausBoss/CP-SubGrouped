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
	int ans =0;
	void func(TreeNode *root, int ret){
		//base case
		if(root == NULL){return;}
		if(root->left==NULL && root->right==NULL){
			ret = (ret * 2) + root->val;
			ans += ret;
			return;
		}
		//recrusive case
		func(root->left, ret*2 + root->val);
		func(root->right, ret*2 + root->val);

	}
    int sumRootToLeaf(TreeNode* root) {
        func(root, 0);
        return ans;
    }
};