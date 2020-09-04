class Solution {
public:
    vector<int> partitionLabels(string s) {
        	int n = s.length();
        	int last[26]= {0};
        	for(int i=0; i<n; i++){
        		last[s[i]-'a'] = i;
        	}
        	int tillnow=0, cut=-1;
        	vector<int> ans;
        	for(int i=0; i<n; i++){
        		tillnow = max(last[s[i]-'a'], tillnow);
        		if(tillnow == i){
        			ans.push_back(i-cut);
        			cut = i;
        		}
        	}
        	return ans;
    }
};