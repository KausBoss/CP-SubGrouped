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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root)q.push(root);
        bool ender=0;
        while(!q.empty()){
        	auto node = q.front();
        	q.pop();
        	if(node->left != NULL){
        		if(ender){return 0;}
        		q.push(node->left);
        	}
        	else{	
        		ender = 1;
        	}
        	if(node->right !=NULL){
        		if(ender){return 0;}
        		q.push(node->right);
        	}
        	else{
        		ender=1;
        	}
        }
        return 1;
    }
};