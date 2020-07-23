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
	TreeNode* func(TreeNode *root, int v, int d){
		//base case
		if(root == nullptr){
			return nullptr;
		}
		if(d == 2){
			TreeNode *nl= new TreeNode(v, root->left, nullptr);
			root->left = nl;
			TreeNode *nr= new TreeNode(v, nullptr, root->right);
			root->right = nr;
			return root;
		}
		root->left = func(root->left, v, d-1);
		root->right = func(root->right, v, d-1);
		return root;
	}
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
        	TreeNode *n = new TreeNode(v, root, nullptr);
        	return n;
        }
        root = func(root, v, d);
        return root;
    }
};