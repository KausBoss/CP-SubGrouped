class Solution {
public:
    void nextPermutation(vector<int>& A) {
        if(A.size() <= 1){return;}
        int n = A.size();
        set<pair<int, int>> s;
        s.insert({A[n-1], n-1});
        for(int i=n-2; i>=0; i--){
        	auto pt = s.upper_bound({A[i], (int)1e6});
        	if(pt != s.end()){
        		int id = pt->second;
        		swap(A[i], A[id]);
        		sort(A.begin()+i+1, A.end());
        		return;
        	}
        	else{
        		s.insert({A[i], i});
        	}
        }
        sort(A.begin(), A.end());
        return;
    }
};