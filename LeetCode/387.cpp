class Solution {
public:
    int firstUniqChar(string s) {
        map<char, vector<int>> m;
        for(int i=0; i<s.length(); i++){
            m[s[i]].push_back(i);
        }
        int ans=s.length();
        for(auto x:m){
            if(x.second.size() == 1){
                ans = min(ans, x.second[0]);
            }
        }
        return (ans==s.length()) ? -1 : ans;
    }
};