class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        vector<int> ans;
        priority_queue<pair<int, pair<int, int>>> p;
        int n=a.size();
        int m=a[0].size();
        p.push({-a[0][0], {0, 0}});
        while(p.size() && ans.size()<k){
        	auto tp = p.top();
        	p.pop();
        	int i= tp.second.first;
        	int j= tp.second.second;
            
        	ans.push_back(tp.first);
        	if(j==0 && i+1<n){p.push({-a[i+1][j], {i+1, j}});}

        	if(i<n && j+1<m){p.push({-a[i][j+1], {i, j+1}});}
        }
        return -ans.back();
    }
};