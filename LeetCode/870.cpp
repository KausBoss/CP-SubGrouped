class Solution {
public:
    vector<int> advantageCount(vector<int> A, vector<int>& B) {
        multiset<int> s;
        for(auto x:A){s.insert(x);}
        A.clear();
        for(auto x:B){
        	auto pt = s.upper_bound(x);
        	if(pt == s.end()){
        		A.push_back(*s.begin());
        		s.earse(s.begin());
        	}
        	else{
        		A.push_back(*pt);
        		s.earse(pt);
        	}
        }
        return A;
    }
};