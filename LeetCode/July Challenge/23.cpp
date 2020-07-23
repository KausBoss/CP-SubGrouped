class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> m;
        for(auto x:nums){
        	m[x]++;
        }
        vector<int> ans;
        for(auto x:m){
        	if(x.second == 1){
        		ans.push_back(x.first);
        	}
        }
        return ans;
    }
};