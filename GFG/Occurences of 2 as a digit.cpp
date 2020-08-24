// { Driver Code Starts
// C++ program to count 2s from 0 to n
#include <bits/stdc++.h>
using namespace std;

/* Counts the number of 2s in a number at d-th
   digit */
long long int count2sinRangeAtDigit(long long int number, long long int d);
/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number);

// Driver Coden
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
    long long int n;
    long long int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout << numberOf2sinRange(n) << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Counts the number of 2s in a number at d-th
   digit */
long long int count2sinRangeAtDigit(long long int number, long long int d){
	int powerOf10 = (int)pow(10, d); 
    int nextPowerOf10 = powerOf10 * 10; 
    int right = number % powerOf10; 
  
    int roundDown = number - number % nextPowerOf10; 
    int roundup = roundDown + nextPowerOf10; 
  
    int digit = (number / powerOf10) % 10; 
    
	if (digit < 2) 
        return roundDown / 10; 
  
    if (digit == 2) 
        return roundDown / 10 + right + 1; 
  
    return roundup / 10;
}

long long int numberOf2sinRange(long long int number){
	long long int ans = 0;
	long long int lim = floor(log10(number));
	for(long long int d=0; d<=lim; d++){
		ans += count2sinRangeAtDigit(number, d);
	}
	return ans;
}
