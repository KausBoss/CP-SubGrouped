class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        priority_queue <pair<int,char>> p;
        for(auto x:s){
            if(m.count(x)){
                m[x]++;
            }
            else{
                m[x]=1;
            }
        }
        for(auto x:m){
            p.push(make_pair(x.second, x.first));
        }
        s="";
        while(!p.empty()){
            int freq=p.top().first;
            while(freq--){
                s += p.top().second;
            }
            p.pop();
        }
        return s;
    }
};