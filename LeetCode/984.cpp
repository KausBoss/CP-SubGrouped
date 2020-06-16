class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string ans; int i=0;
        priority_queue<pair<int, char>> pq;
        pq.push({A, 'a'});
        pq.push({B, 'b'});
        while(ans.length() < A+B){
        	auto p = pq.top();
        	pq.pop();
        	if(i > 1 && ans[i-1] == p.second && ans[i-2] == p.second){
        			auto p2 = pq.top();
        			pq.pop();
        			ans.push_back(p2.second);
        			p2.first--;
        			pq.push(p2);
        			pq.push(p);
        	}
        	else {
        		ans.push_back(p.second);
        		p.first--;
        		pq.push(p);
        	}
        	i++;
        }
        return ans;
    }
};