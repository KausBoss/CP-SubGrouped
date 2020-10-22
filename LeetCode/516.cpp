class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length(), ans=1;
        if(n==0){return 0;}
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){dp[i][i]=1;}
        for(int i=1; i<n; i++){
            if(s[i-1] == s[i]){dp[i-1][i]=2;}
            else{dp[i-1][i]=1;}
            ans = max(ans, dp[i-1][i]);
        }
        
        for(int k=2; k<n; k++){
            int j=k, i=0;
            while(j<n){
                dp[i][j] = dp[i+1][j-1];
                if(s[i] == s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
                ans = max(ans, dp[i][j]);
                j++;i++;
            }
        }
        return ans;
    }
};