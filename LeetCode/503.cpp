class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size(), -1);
        for(int i=0; i<nums.size(); i++){
        	while(!s.empty() && nums[i] > nums[s.top()]){
        		ans[s.top()] = nums[i];
        		s.pop();
        	}
        	s.push(i);
        }
        for(int i=0; i<nums.size(); i++){
        	while(!s.empty() && nums[i] > nums[s.top()]){
        		ans[s.top()] = nums[i];
        		s.pop();
        	}
        	s.push(i);
        }
        return ans;
    }
};