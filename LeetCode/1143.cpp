class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        t1 = ' '+t1;
        t2 = ' '+t2;
        int n=t1.size(), m=t2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(t1[i] == t2[j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};