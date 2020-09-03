class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n= s.length();
        int j=0, i=1;
        vector<int> dp(n, 0);
        while(i<n){
        	if(s[i] != s[j]){
        		if(j!=0){j=dp[j-1];}
        		else{i++;}
        	}
        	else{
        		dp[i++] = ++j;
        	}
        }
        return (dp[n-1]>0 && (n%(n-dp[n-1])==0) ) ? 1  : 0;
    }
};