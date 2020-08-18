/*
*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
#define mp          make_pair
#define pb          push_back
#define fi          first
#define si          second
#define fastIO      ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n)      for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n)     for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n)      for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n)     for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;


void func(){
	ll n; cin>>n;
	ll *a = new ll[n];
	F(a, n);
	sort(a, a+n);
	ll x;cin>>x;
	if(x < a[0]){
		cout<<"Floor of "<<x<<" doesn't exists\n";
	}
	else{
		ll s=0, e=n-1, ans;
		while(s <= e){
			ll mid = (s+e)/2;
			// cout<<s<<" "<<mid<<" "<<e<<" "<<a[mid]<<endl;
			if(a[mid] == x){
				ans = mid;
				break;
			}
			if(a[mid] > x){
				e = mid - 1;
			}
			else{
				ans = mid;
				s = mid + 1;
			}
		}
		cout<<"Floor of "<<x<<" is at "<<ans<<" and as "<<a[ans]<<endl;
	}

	//finding ceil value
	if(x > a[n-1]){
		cout<<"Ceil of "<<x<<" doesn't exists\n";
	}
	else{
		ll s=0, e=n-1, mid, ans;
		while(s <= e){
			ll mid = (s+e)/2;
			if(a[mid] == x){
				ans = mid;
				break;
			}
			if(a[mid] > x){
				ans = mid;
				e = mid - 1;
			}
			else{
				s = mid+1;
			}
		}
		cout<<"Ceil of "<<x<<" is at "<<ans<<" and as "<<a[ans]<<endl;
	}
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("../inp.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
	#endif
	int t;cin>>t;
	while(t--){
		func();
	}
}