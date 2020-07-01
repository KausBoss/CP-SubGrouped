class Solution {
	int s, dp[21][2002];
	int func(int i, int sum, vector<int> n){
		//base case
		if(i == n.size()){return sum==s;}
		//recursive case
		if(dp[i][sum+1000] != -1){return dp[i][sum+1000];}

		return dp[i][sum + 1000] = func(i+1, sum+n[i], n) + func(i+1, sum-n[i], n);
	}
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        s = S;
        memset(dp, -1, sizeof(dp));
        return func(0, 0, nums);
    }
};