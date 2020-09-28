class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
    	int n=a.size(), j=0;
        int ans=0;
        int prod = 1;
        for(int i=0; i<n; i++){
        	prod *= a[i];
        	while(prod >= k && j < i){
        		prod /= a[j++];
        	}
        	ans += (i-j+1);
        	if(i==j && a[i] >= k){ans--;}
        }
        return ans;
    }
};