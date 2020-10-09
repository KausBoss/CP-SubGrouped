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
	int n, i;
	TreeNode* func(vector<int>& postorder, vector<int>& inorder, int s, int e){
        if(i <0){return NULL;}
		//base case
		if(s > e){
			return NULL;
		}
		//recursive case
		TreeNode* root = new TreeNode(postorder[i]);
		int index;
		for(int j=s; j<=e; j++){
			if(inorder[j] == postorder[i]){
				index = j;
				break;
			}
		}
		i--;
		root->right = func(postorder, inorder, index+1, e);
		root->left = func(postorder, inorder, s, index-1);
		return root;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size()-1;
        i = n;
        return func(postorder, inorder, 0, n);
    }
};