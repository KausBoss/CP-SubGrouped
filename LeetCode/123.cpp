/*
find DP1[i] - max profit by 1 tracastion till day i;
find DP2[i] = max profit by 1 transaction beyond day i (incudes day i)
a = max of DP1[i] + DP2[i+1] for i[1, n]
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n == 0){return 0;}
        int minVal=prices[0], prof=0;
        vector<int> dp1(n, 0), dp2(n+1, 0);
        for(int i=1; i<n; i++){
        	prof= max(prof, prices[i]-minVal);
            dp1[i] = prof;
        	minVal = min(minVal, prices[i]);
        }
        int maxVal=prices[n-1]; prof=0;
        for(int i=n-2; i>=0; i--){
        	prof = max(prof, maxVal-prices[i]);
        	dp2[i] = prof;
            maxVal = max(maxVal, prices[i]);
        }
        int ans=0;
        for(int i=1; i<n; i++){
        	ans = max(ans, dp1[i] + dp2[i+1]);
        }
        return ans;
    }
};