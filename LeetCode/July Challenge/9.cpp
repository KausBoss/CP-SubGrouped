typedef unsigned long long int ull;

void fillDataLevelWise(TreeNode* root,unordered_map<int,pair<int,int>>& mp,ull currLevel,ull position){
    
    if(!root)   return ;
    
    if(mp.find(currLevel) == mp.end()){
        mp[currLevel] = make_pair(position,position);
    }else{
        pair<int,int> p = mp[currLevel];
        if(p.first > position)  p.first = position;
        if(p.second < position) p.second = position;
        mp[currLevel] = p;    
    }
    
    fillDataLevelWise(root->left,mp,currLevel+1,2*position);
    fillDataLevelWise(root->right,mp,currLevel+1,2*position + 1);
}

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        //completely different solution and approach as I wass thinking about it
        //requires use of map also mapping along with the depth
        if(!root)   return 0;
        unordered_map<int,pair<int,int>> mp;
        fillDataLevelWise(root,mp,0,1);
        
        unordered_map<int,pair<int,int>>::iterator it;
        
        int maxWidth = 0;
        
        for(it=mp.begin();it!=mp.end();it++){
            
            int left = it->second.first;
            int right = it->second.second;
            int t = right-left+1;
            maxWidth = max(t,maxWidth);
            
        }
        
        return maxWidth;
    }
};