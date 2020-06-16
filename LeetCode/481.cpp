class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i = 2;
        while(s.length() < n){
        	char ch = (i&1) == 1 ? '2' : '1';
        	int freq = s[i] - '0';
        	while(freq--){
        		s.push_back(ch);
        	}
        	i++;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
        	if(s[i] == '1'){
                ans++;
            }
        }
        // cout<<s;
        return ans;
    }
};