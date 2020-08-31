class Solution {
public:
    vector<int> store;
    void findVal(TreeNode *root, int level){
        //base case
        if(root==NULL){
            return;
        }
        //recursive case
        store[level] += root->val;
        findVal(root->left, level+1);
        findVal(root->right, level+1);
        return;
    }
    int maxLevelSum(TreeNode* root) {
        store = vector<int>(10004, 0);
        findVal(root, 0);
        int maxVal = -1e5;
        for(int i=0; i<10004; i++){
            if(store[i] == 0){break;}
             maxVal = max(maxVal, store[i]);
        }
        for(int i=0; i<10004; i++){
            if(store[i] == maxVal){
                return i+1;
            }
        }
        return 0;
    }
};