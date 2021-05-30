/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           		long long int
#define vi 				 	vector<int>
#define pb      	     	push_back
#define fi          	 	first
#define si      	     	second
#define pii		 		 	pair<int,int>
#define vii 			 	vector<pair<int,int>>
#define F(a,n)  	     	for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n) 		    	for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define fastIO      	 	ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F1(a,n) 	     	for(int i=1;i<=n;i++){cin>>a[i];}
#define P1(a,n)     		for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define mem(a,b)	     	memset(a, b, sizeof a)
#define matrix(x) 		 	vector<vector<x>>
#define NF(a,n,m)      	    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)		    for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  	 	for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define ceil_div(x, y) 		(((x) + (y) - 1) / (y))
const int nax = 1e7;
const int mod = 1e9+7;

vector<pair<int, int>> bf(int arr[], int size, int target){
	vector<pair<int, int>> ans;
	
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(arr[i] + arr[j] == target){
				ans.push_back({arr[i], arr[j]});
			}
		}
	}
	return ans;
}

bool binarySearch(int arr[], int start, int end, int target){
	while(start <= end){
		
		int mid = (start + end)/2;

		if(arr[mid] == target){
			return true;
		}
		else if(arr[mid] > target){
			end = mid - 1; 
		}
		else{
			start = mid + 1;
		}
	}
	return false;
}

vector<pair<int, int>> srt(int arr[], int size, int target){
	vector<pair<int, int>> ans;

	sort(arr, arr + size);

	for(int i=0; i<size; i++){
		
		int compliment = target - arr[i];
		bool present = binarySearch(arr, i+1, size-1, compliment);
		
		if(present){
			ans.push_back({arr[i], compliment});
		}
	}
	return ans;
}

vector<pair<int, int>> hshmp(int arr[], int size, int target){
	map<int, int>
}

void func(){
	int arr[] = {10, 5, 2, 3, -6, 9, 11};
	int size = sizeof(arr)/sizeof(int);
	int target = 4;

	//Brute Force approach
	cout<<"Brute Force approach\n";
	vector<pair<int, int>> a = bf(arr, size, target);
	for(auto x : a){
		cout<<x.fi<<", "<<x.si<<"\n";
	}

	//Using Sorting
	cout<<"\nUsing Sorting\n";
	vector<pair<int, int>> b = srt(arr, size, target);
	for(auto x : b){
		cout<<x.fi<<", "<<x.si<<"\n";
	}

	//Using Hashmap
	// vector<pair<int, int>> c = hshmp(arr, size, target);

}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;//cin>>t;
	while(t--){
		func();
	}
}