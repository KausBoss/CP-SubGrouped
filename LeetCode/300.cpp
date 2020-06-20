class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
        		int MaxHere = 1;
        	for(int j = 0; j < i; j++){
        		if(nums[j] < nums[i]){
        			MaxHere = max(MaxHere, dp[j] + 1);
        		}
        	}
        	dp[i] = MaxHere;
        }
        int ans = 0 ;
        for(int i=0; i<n; i++){
        	ans = max(ans, dp[i]);
        }
        return ans;
    }
};