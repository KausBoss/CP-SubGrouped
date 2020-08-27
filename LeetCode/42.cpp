class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2){ return 0;}
        vector<int> left(n,0), right(n, 0);
        int seenMax=height[0];
        for(int i=1; i<n; i++){
        	left[i] = seenMax;
        	seenMax = max(height[i], seenMax);
        }
        seenMax = height[n-1];
        for(int i=n-2; i>=0; i--){
        	right[i] = seenMax;
        	seenMax = max(height[i], seenMax);
        }
        int ans=0, bank;
        for(int i=0; i<n; i++){
        	cout<<left[i]<<" "<<right[i]<<endl;
        	bank = min(left[i], right[i]);
        	ans += max(0, bank - height[i]);
        }
        return ans;
    }
};