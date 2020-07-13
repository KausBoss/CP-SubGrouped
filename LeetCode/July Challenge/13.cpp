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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)){
        	return 0;
        }
        if(p==NULL && q==NULL){
        	return 1;
        }
        //recursive case
        if(p->val != q->val){
        	return 0;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};