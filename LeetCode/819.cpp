class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
  		queue<char> q;
  		string gg = "!?',;. ";
  		map<char, bool> special;
  		for(auto x:gg)special[x]=1;
  		paragraph += " ";
  		map<string, int> m;
  		for(auto ch: paragraph){
  			ch = tolower(ch);
  			if(special[ch] == 1){
  				string st="";
  				while(!q.empty()){
  					st += q.front();
  					q.pop();
  				}
  				if(st!=""){
  					m[st]++;
  				}
  			}
  			else{
  				q.push(ch)
  			}
  		} 		
  		for(int i=0; i<banned.size(); i++){
  			m[banned[i]]=0;
  		}
  		string ret;
  		int freq=0;
  		for(auto x:m){
  			if(x.second > freq){
  				ret = x.first;
  				freq = x.second;
  			}
  		}
  		return ret;
    }
};