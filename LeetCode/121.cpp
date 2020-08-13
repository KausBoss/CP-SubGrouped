class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if(n == 0){return 0;}
        int minElement= p[0];
        int ans=0;
        for(int i=1; i<n; i++){
        	ans = max(ans, p[i] - minElement);
        	minElement = min(minElement, p[i]);
        }
        return ans;
    }
};