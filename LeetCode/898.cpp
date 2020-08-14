class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        set<int> ans;
        vector<int> dp(A.size());
        int pre = -1;
        for(int i=0; i<A.size(); i++){
        	if(A[i] == pre){
        		dp[i] = A[i];
        		continue;
        	}
        	pre = A[i];
        	if(A[i] == 0){
        		ans.insert(0);
        	}
        	else{
        		for(int j=i; j>=0; j--){
        			int v = A[i] | dp[j];
        			if(v == dp[j]){break;}
        			dp[j] = v;
        			ans.insert(v);
        		}
        	}
        }
        return ans.size();
    }
};