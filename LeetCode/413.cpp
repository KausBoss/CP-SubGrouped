class Solution {
public:
	int NcR(int n, int r){
		int ans = 1;
		int div = 2;
		for(int i = n; i>r; i--){
			ans *= i;
			if(ans % div == 0 && div <= (n - r)){
				ans /= div++;
			}
		}
		return ans;
	}
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> diff;
        for(int i=1; i<A.size(); i++){
        	diff.push_back(A[i] - A[i-1]);
        }
        int I=0, J=0, ans=0;
        for(int i=1; i<diff.size(); i++){
        	if(diff[i] == diff[i-1]){
        		J++;
        	}
        	else{
        		int options = J - I + 2;
        		if(options > 2){
        			ans += NcR(options, 2) - options + 1;
        		}
        		I = i;
        		J = i;
        	}
        }
        int options = J - I + 2;
		if(options > 2){
			ans += NcR(options, 2) - options + 1;
		}
        return ans;
    }
};