class Solution {
	int dp[500][500];
public:
	int func(int i, int j, vector<int> A, vector<int> B){
		//base case
		if(i == A.size() || j == B.size()){
			return 0;
		}
		//recursive case
		if(dp[i][j] != -1){ return dp[i][j];}

		int ans = func(i+1, j, A, B);
		for(int k = j; k<B.size(); k++){
			if(A[i] == B[k]){
				ans = max(ans, 1 + func(i+1, k+1, A, B));
                break;// we break here because any match further will always give 
                //either same or worse ans
			}
		}
		return dp[i][j] = ans;
	}
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        memset(dp, -1, sizeof(dp));
        return func(0, 0, A, B);
    }
};