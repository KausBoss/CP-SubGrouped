class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int lastDay = days[n-1];
        map<int, bool> m;
        for(auto x:days){m[x]=1;}
        vector<int> dp(lastDay+1, 0);
    	for(int i=1; i<=lastDay; i++){
    		dp[i] = dp[i-1];
    		if(m[i]){dp[i] += costs[0];}
    		if(i>=7){dp[i] = min(dp[i], dp[i-7] + costs[1]);}
    		else{dp[i] = min(dp[i], costs[1]);}
    		if(i>=30){dp[i] = min(dp[i], dp[i-30] + costs[2]);}
    		else{dp[i] = min(dp[i], costs[2]);}
    	}
    	return dp[lastDay];
    }
};