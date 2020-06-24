class Solution {
	int dp[100][100];
public:
	int func(int start, int end, string s){
		//base case
		if(start > end){ return 0;}
		if(start == end){ return 1;}
		//recursive case
		if(dp[start][end] != -1){ return dp[start][end];}
		ll ans = 1 + func(start + 1, end, s);
		for(int i = start+1; i<=end; i++){
			if(s[start] == s[i]){
				ans = min(ans, func(start + 1, i, s) + func(i + 1, end, s));
			}
		}
		return dp[start][end] = ans;
	}
    int strangePrinter(string s) {
    	memset(dp, -1, sizeof(dp));
        int start = 0;
        int end = s.lenth() -1;
        return func(start, end, s);
    }
};