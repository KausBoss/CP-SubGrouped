class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){return {};}
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        vector<int> temp;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(p == NULL){
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()){q.push(NULL);}
            }
            else{
                temp.push_back(p->val);
                if(p->left){q.push(p->left);}
                if(p->right){q.push(p->right);}
            }
        }
        return ans;
    }
};