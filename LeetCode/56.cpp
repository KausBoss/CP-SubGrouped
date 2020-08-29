class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        int n=a.size();
        if(n==0){return {};}
        int s=a[0][0], last=a[0][1];
        for(int i=1; i<n; i++){
            if(a[i][0] <= last){
                last = max(last, a[i][1]);
            }
            else{
                ans.push_back({s, last});
                s = a[i][0];
                last = a[i][1];
            }
        }
        ans.push_back({s, last});
        return ans;
    }
};