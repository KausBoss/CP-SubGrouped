class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, vector<int>> dp;
        int n=nums.size();
        for(int i=0; i<n; i++){
        	dp[i]={};
        	for(int j=0; j<i; j++){
        		if(nums[j]==0 || (nums[i]%nums[j]==0 && dp[j].size() > dp[i].size())){
        			dp[i] = dp[j];
        		}
        	}
        	dp[i].push_back(nums[i]);
        }
        int id=0;
        for(int i=1; i<n; i++){
        	if(dp[id].size() < dp[i].size()){
        		id = i;
        	}
        }
        return dp[id];
    }
};