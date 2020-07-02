class Solution {
	map<pair<int, pair<int,int>>, int> dp;
public:
	static bool srt(vector<int> a, vector<int> b){
		if(a[0] == b[0]){return a[1] > b[1];}
		return a[0] > b[0];
	}
    int maxEnvelopes(vector<vector<int>> en) {
        int n= en.size();
        sort(en.begin(), en.end(), srt);
        vector<int> dp(n, 1);
        for(int i=0; i<n; i++){
        	for(int j=0; j<i; j++){
        		if(en[i][0] < en[j][0] && en[i][1] < en[j][1]){
        			dp[i] = max(dp[i], 1 + dp[j]);
        		}
        	}
        }
        int ans=0;
        for(int i=0; i<n; i++){ans = max(dp[i], ans);}
        return ans;
    }
};