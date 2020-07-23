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
    TreeNode* deleteNode(TreeNode* root, int key) {
    	//base case
    	if(root == nullptr){
    		return nullptr;
    	}
    	//recursive case
    	if(key < root->val){
    		root->left = deleteNode(root->left, key);
    		return root;
    	}
    	else if(key == root->val){
    		//case 1. no child
    		if(root->left == NULL && root->right == NULL){
    			delete root;
    			return NULL;
    		}
    		//case 2. 1 child
    		if(root->left!=NULL && root->right==NULL){
    			TreeNode *temp = root->left;
    			delete root;
    			return temp;
    		}
    		if(root->left==NULL && root->right!=NULL){
    			TreeNode *temp = root->right;
    			delete root;
    			return temp;
    		}
    		//case 3. has both children
    		if(root->left != NULL && root->right != NULL){
    			TreeNode *rep = root->right;
    			while(rep->left != NULL){
    				rep = rep->left;
    			}
    			root->val = rep->val;
    			root->right = deleteNode(root->right, rep->val);
    			return root;
    		}
    	}
    	if(key > root->val){
    		root->right = deleteNode(root->right, key);
    		return root;
    	}
    	return root;
    }
};