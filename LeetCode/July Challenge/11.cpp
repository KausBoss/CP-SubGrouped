class Solution {
public:
	vector<vector<int>> ans;
	void func(int i, vector<int> nums, vector<int> pb){
		//base case
		if(i == nums.size()){
			ans.push_back(pb);
			return;
		}
		//recursive case
		func(i+1, nums, pb);
		pb.push_back(nums[i]);
		func(i+1, nums, pb);
	}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        func(0, nums, v);
        return ans;
    }
};