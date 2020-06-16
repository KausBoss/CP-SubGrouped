class Solution {
public:
    string orderlyQueue(string S, int K) {
        if(K > 1){
        	sort(S.begin(), S.end());
        	return S;
        }
        string ans = S;
        for(int i=0; i<S.size()-1; i++){
        	reverse(S.begin(), S.end());
        	reverse(S.begin() + 1, S.end());
        	if(S < ans){
        		ans = S;
        	}
        }
        return ans;
    }
};