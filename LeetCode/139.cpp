class Solution {
	unordered_map<string, bool> m;
	int *dp;
public:
	bool func(int i, string s){
		//base case
		if(i == s.length()){
			return 1;
		}
		//recursive case
		if(dp[i] != -1){return dp[i];}
		string temp = "";
		for(int j = i; j<s.length(); j++){
			temp.push_back(s[j]);
			if(m.count(temp) && func(j+1, s)){
				return dp[i] = 1;
			}
		}
		return dp[i] = 0;
	}
    bool wordBreak(string s, vector<string>& wordDict) {
    	dp = new int[s.length()+1];
    	for(int i=0; i<s.length()+1; i++){
            dp[i]=-1;
        }
        for(auto x:wordDict){
        	m[x] = 1;
        }

        return func(0, s);
    }
};