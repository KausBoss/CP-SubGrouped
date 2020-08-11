/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //Left Shift and Right shift
    //Left shift is divide by 2
    //right shift is multiply by 2

    int n=16;
    cout<<n<<" "<<(n>>1)<<" "<<(n<<1)<<endl;

    //Find Unique Number where all number appear twice ans
    // unique number appears once
    //Ans: XOR all numbers
    vector<int> v{1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 8};
    int ans=0;
    for(auto x: v){
    	ans ^= x;
    }
    cout<<ans<<endl;
    // --------------------------------------------------------

    //Find bit at ith place in a number
    //Ans- make a mask with 1 only at ith place
    //take &
    int num = 13321;
    int pos = 3;
    int mask = 1<<pos;
    if(mask&num){
    	cout<<1<<endl;
    }
    else{
    	cout<<0<<endl;
    }

    //Set ith bit in a number
    //Ans- make a mask with 1 only at ith place
    //take OR
    cout<<(num|(1<<pos))<<endl;


    //Clear bit at ith place
    //Ans: make a mask with 1 at ith place
    // take compliment of the mask
    // take AND of num and mask
    mask = ~(1<<pos);
    cout<<(num&mask)<<endl;

    // ??IMPORTANT
    // a+b = a^b + 2(a&b)

    //Clear last i bits
    //create a mask ~0
    //right-shift i places
    int num2 = 15;
    int pos2 = 2;
    int mask2 = ((~0)<<2);
    cout<<(num2&mask2)<<endl;


    //Clear Range of bits btw i and j( i <= j);
    //Ans: Lest mask be (a|b) 
    // a = (~0)<<(j+1)
    // b is (2**n) - 1 = (pow(2, i) - 1) = (2<<i) - 1
    //mask = a|b 
    // ans = num&mask

    
}