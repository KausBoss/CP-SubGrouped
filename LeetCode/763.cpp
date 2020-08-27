class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> freq(26, 0);
        int n=S.length();;
        for(int i=0; i<n; i++){
        	freq[S[i]-'a']=i;
        }
        priority_queue<int> p;
        int last=0;
        vector<int> ans;
        for(int i=0; i<n; i++){
            // cout<<i<<" "<<last<<endl;
        	if(!p.empty() && p.top()<i){
        		ans.push_back(i - last);
        		last = i;
        		p = priority_queue<int>();
        	}
        	p.push(freq[S[i]-'a']);
        }
        if(!p.empty() && p.top() < n){
        		ans.push_back(n - last);
        }
        return ans;
    }
};