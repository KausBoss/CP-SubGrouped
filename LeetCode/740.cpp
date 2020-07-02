class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int freq[1001]={0};
        for(auto x:nums){freq[x]++;}
        int dp[1001]={0};
    	dp[1] = freq[1];

    	for(int i=2; i<1001; i++){
    		dp[i] = max(i*freq[i] + dp[i-2], dp[i-1]);
    	}
    	return dp[1000];
    }
};