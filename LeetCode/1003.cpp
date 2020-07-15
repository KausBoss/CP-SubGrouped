class Solution {
public:
    bool isValid(string S) {
        stack<char> s;
        for(auto x:S){
            if(x == 'c'){
                if(s.size() < 2){
                    return false;
                }
                char temp =s.top();
                s.pop();
                if(s.top() == 'a' && temp == 'b'){
                    s.pop();
                }
                else{
                    s.push(temp);
                    s.push(x);
                }
            }
            else{
                s.push(x);
            }
        }
        return s.empty();
    }
};