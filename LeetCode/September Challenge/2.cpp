class Solution {
public:
	#define ll long long int
    bool containsNearbyAlmostDuplicate(vector<int>& a, int K, int T) {
    	ll k = K;
    	ll t = T;
    	ll n = a.size();
        if(k==0 || n<=1){return 0;}
    	set<ll> s;
    	map<ll, ll> freq;
    	for(int i=0; i<k && i<n; i++){s.insert(a[i]);freq[a[i]]++;}
    	for(int i=0; i<n; i++){
    		freq[a[i]]--;
    		if(freq[a[i]] == 0){s.erase(a[i]);}
    		if(i+k < n){s.insert(a[i+k]);freq[a[i+k]]++;}
    		auto it = s.upper_bound(a[i]);
    		if(it != s.end() && abs(*it-(ll)a[i])<=t){return 1;}
    		if(it!=s.begin() && abs(*prev(it)-a[i])<=t){return 1;}
    	}
    	return 0;
    }
}; 