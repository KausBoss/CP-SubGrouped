#define fi first
#define si second

static bool sorter(val a, val b){
	return a.si < b.si; 
}

int maxChainLen(struct val p[],int n){
	sort(p, p+n, sorter);
	int ans=0, end=-1;
	for(int i=0; i<n; i++){
		if(end < p[i].fi){
			ans++;
			end = p[i].si;
		}
	}
	return ans;
}