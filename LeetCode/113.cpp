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
	vector<vector<int>> ans;
	void func(TreeNode *root, vector<int> v, int sum, int k){
		//base case
		if(root == NULL){
			return;
		}
		//recursive case
		sum += root->val;
		v.push_back(root->val);
		if(sum == k && root->left==NULL && root->right==NULL){
			ans.push_back(v);
			return;
		}
		func(root->left, v, sum, k);
		func(root->right, v, sum, k);
	}
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> v;
        func(root, v, 0, sum);
        return ans;
    }
};