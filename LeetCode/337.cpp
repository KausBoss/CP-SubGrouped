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
	map<pair<TreeNode*, bool>, int> m;
	int func(TreeNode *root, bool marzi){
		//base case
		if(root == NULL){
			return 0;
		}
		//recursive case
		if(m.count({root, marzi})){return m[{root, marzi}];}

		if(marzi){
			return m[{root, marzi}] = max(root->val + func(root->left, 0) + func(root->right, 0),
					   func(root->left, 1) + func(root->right, 1));
		}
		return m[{root, marzi}] = func(root->left, 1) + func(root->right, 1);
	}
    int rob(TreeNode* root) {
        return func(root, 1);
    }
};