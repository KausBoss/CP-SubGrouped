class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> arr;
        for(int i=0; i<(1<<n); i++){
        	arr.push_back(i^(i>>1));
        }
        int j = 0;
        for(int i=0; i<arr.size(); i++){
        	if(arr[i] == start){j = i; break;}
        }
        vector<int> ans;
        for(int i=j; i<arr.size(); i++){
        	ans.push_back(arr[i]);
        }
        for(int i=0; i<j; i++){
        	ans.push_back(arr[i]);
        }
        return ans;
        
    }
};