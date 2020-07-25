class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto x: nums){
        	mini = min(mini, x);
        }
        return mini;
    }
};