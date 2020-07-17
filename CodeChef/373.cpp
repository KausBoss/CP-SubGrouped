class Solution {
	class cls{
	public:
		int n1, n2, sum;
		cls(int n1, int n2){
			this->n1=n1;
			this->n2=n2;
			sum=n1+n2;
		}
	};
	struct comp{
		bool operator()(cls const &a, cls const &b){
			return a.sum < b.sum;
		}
	};
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
    	priority_queue<cls, vector<cls>, comp> p;
    	for(auto x:nums1){
    		for(auto y:nums2){
    			cls n(x,y);
    			p.push(n);
    			if(p.size() > k){
    				p.pop();
    			}
    		}
    	}
    	vector<vector<int>> ans;
    	while(!p.empty()){
    		ans.push_back({p.top().n1, p.top().n2});
    		p.pop();
    	}
        return ans;
    }
};