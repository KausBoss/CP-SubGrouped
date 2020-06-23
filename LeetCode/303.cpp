class NumArray {
	vector<int> a, prefix;
public:
    NumArray(vector<int>& nums) {
		a = nums;
		prefix.resize(nums.size());
		for(int i=0; i<nums.size(); i++){
			if(i != 0){
				prefix[i] = nums[i] + prefix[i-1];
			}
			else{
				prefix[i] = nums[i];
			}
		}        
    }
    
    int sumRange(int i, int j) {
        if(i == 0){
        	return prefix[j];
        }
        return prefix[j] - prefix[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */