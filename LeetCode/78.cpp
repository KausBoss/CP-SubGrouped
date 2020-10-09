class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<(1<<n); i++){
        	int temp = i;
        	int pos = 0;
            vector<int> adder;
        	while(temp > 0){
        		if(temp&1){
        			adder.push_back(nums[pos]);
        		}
        		temp /= 2;
        		pos++;
        	}
            ans.push_back(adder);
        }
        return ans;
    }
};