class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
    	int ans=0;
    	int n = A.size();
    	for(int i=0; i<n; i++){
    		for(int j=0; j<n; j++){
    			for(int k=0; k<n; k++){
    				for(int l=0; l<n; l++){
    					int rowtrav = min(n-i, n-k);
    					int coltrav = min(n-j, n-l);
    					int cur =0;
    					for(int row=0; row<rowtrav; row++){
    						for(int col=0; col<coltrav; col){
    							if(A[i+row][j+col] && B[k+row][l+col]){
    								cur++;
    							}
    						}
    					}
    					ans = max(ans, cur);
    				}
    			}
    		}
    	}
    	return ans;
    }
};