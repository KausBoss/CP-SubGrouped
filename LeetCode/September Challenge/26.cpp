class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        int ans=0, current=0;
        for(auto x:t){
        	if(x >= current){
        		ans += d;
        	}
        	else{
        		ans += (x+d - current);
        	}
        	current = x+d;
        }
        return ans;
    }
};