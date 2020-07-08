class Solution {
public:
    vector<vector<int>> threeSum(vector<int> a) {
        int n=a.size();
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for(int i=0; i<n-2; i++){
        	if(i != 0 && a[i] == a[i-1]){continue;}
        	int j=i+1, k=n-1;
        	while(j < k){
        		if(a[j] == a[j-1] && j!=i+1){j++;}

        		else if(a[i] + a[j] + a[k] == 0){
        			ans.push_back({a[i], a[j], a[k]});
        			j++;		
        		}
        		else if(a[i] + a[j] + a[k] > 0){
        			k--;
        		}
        		else{
        			j++;
        		}
        	}
        }
        return ans;
    }
};