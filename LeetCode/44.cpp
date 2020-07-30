class Solution {
public:
    bool isMatch(string s, string p) {
        s = '#' + s;
        p = '#' + p;
        int n=s.length(), m=p.length();
        vector<vector<bool>> dp(n, vector<bool>(m, 0));
        dp[0][0]=1;
        for(int i=1; i<m; i++){
        	if(p[i] != '*'){break;}
        	dp[0][i]=1;
        }

        for(int i=1; i<n; i++){
        	for(int j=1; j<m; j++){
        		if(s[i]==p[j] || p[j]=='?'){
        			dp[i][j] = dp[i-1][j-1];
        		}
        		else if(p[j] == '*'){
        			dp[i][j] = dp[i-1][j]|dp[i-1][j-1]|dp[i][j-1];
        		}
        	}
        }
       	return dp[n-1][m-1];
    }
};