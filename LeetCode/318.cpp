class Solution {
public:
	static bool func(string a, string b){
		return a.length() < b.length();
	}
    int maxProduct(vector<string> words) {
        int n = words.size();
        sort(words.begin(), words.end(), func);
        vector<int> mask(n, 0);
        for(int i=0; i<n; i++){
        	for(auto ch:words[i]){
        		mask[i] |= (1<<(ch - 'a'));
        	}
        }
        int ans=0;
        for(int i=n-2; i >=0 ; i--){
        	for(int j=n-1; j>i; j--){
        		if(!(mask[i]&mask[j])){
        			if(ans < words[i].length() * words[j].length()){
                        ans = words[i].length() * words[j].length();
                    }
        		}
        	}
        }
        return ans;
    }
};