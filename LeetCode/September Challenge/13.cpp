class Solution {
public:
	static bool func(vector<int> a, vector<int> b){return a[0] < b[0];}
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& intvl) {
        a.push_back(intvl);
        int n = a.size();
        vector<vector<int>> ans;
        sort(a.begin(), a.end(), func);
        int s=a[0][0], e=a[0][1];
        for(int i=1; i<n; i++){
        	if(a[i][0] > e){
        		ans.push_back({s, e});
        		s = a[i][0];
        		e = a[i][1];
        	}
        	else{
        		e = max(e, a[i][1]);
        	}
        }
        ans.push_back({s, e});
        return ans;
    }
};