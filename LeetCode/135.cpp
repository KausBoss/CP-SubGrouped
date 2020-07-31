class Solution {
public:
    int candy(vector<int>& R) {
        int n = R.size();
        vector<int> candy(n, 1);
        for(int i=1; i<n; i++){
        	if(R[i] > R[i-1]){
        		candy[i] = candy[i-1] + 1;
        	}
        }
        for(int i=n-2; i>=0; i--){
        	if(R[i] > R[i+1] && candy[i] <= candy[i+1]){
        		candy[i] = candy[i+1] + 1;
        	}	
        }
        int ans=0;
        for(auto x:candy){ans += x;cout<<x<<" ";}
        return ans;
    }
};