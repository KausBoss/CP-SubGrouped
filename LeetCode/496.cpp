class Solution {
public:
    vector<int> nextGreaterElement(vector<int> nums1, vector<int>& nums2) {
        stack<int> s;
        map<int,int> m;
        for(auto x:nums2){
        	while(!s.empty() && s.top() < x){
        		m[s.top()] = x;
        		s.pop();
        	}
        	s.push(x);
        }
        for(auto &x:nums1){
        	if(m.count(x)){
        		x = m[x];
        	}
        	else{
        		x=-1;
        	}
        }
        return nums1;
    }
};