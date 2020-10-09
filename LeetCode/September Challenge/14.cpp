class Solution {
public:
	int *dp;
	int ans(int i, vector<int> v){
		//base case
		if(i>=v.size()){
			return 0;
		}
		//recursive case
		if(dp[i]!=-1){return dp[i];}

		dp[i]= max(v[i]+ans(i+2, v), ans(i+1, v));

		return dp[i];
	}
    int rob(vector<int>& nums) {
        dp = new int[nums.size()];
        for(int i=0; i<nums.size(); i++){dp[i]=-1;}
        return ans(0, nums);
    }
};