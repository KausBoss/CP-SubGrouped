class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> m;
        for(auto x:nums){
        	m[x]++;
        }
        int mx=0;
        for(auto x:m){
        	int val = x.second;
        	if(m.count(x.first + 1)){
        		val += m[x.first + 1];
        	}
        	else{
        		val = 0;
        	}
        	mx = max(val, mx);
        }
        return mx;
    }
};