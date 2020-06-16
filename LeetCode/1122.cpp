class Solution {
public:
	static bool sorty(pair<int,int> a, pair<int,int> b){
		if(a.first == b.first){
            return a.second < b.second;
        }
		return a.first < b.first;
	}
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int id[1001];
        for(int i=0; i<1001; i++){
            id[i] = 2000;
        }
        for(int i = 0; i < arr2.size(); i++){
        	id[arr2[i]] = i;
        }
        vector<pair<int,int>> pt;
        for(int i=0; i<arr1.size(); i++){
        	pt.push_back({id[arr1[i]], arr1[i]});
        }
        sort(pt.begin(), pt.end(), sorty);
        for(int i=0; i<arr1.size(); i++){
        	arr1[i] = pt[i].second;
        }
        return arr1;
    }
};