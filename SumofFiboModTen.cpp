#include<bits/stdc++.h>
using namespace std;

int fiboModTenSum(long long a){
    int sum = 0;
    vector<int> f(a+1);

	f[0] = 0;
    f[1] = 1;
    
	if(a<=1)
	    sum = sum +f[a];
	else{
	    sum = 1;
        for(int i=2;i<=a;i++){
            f[i] = (f[i-1] + f[i-2]) % 10;
            sum = (sum + f[i]) % 10;
        }
	}
    
    return sum;
}

int main(){
    long long n;
    cin >> n;
    cout<<fiboModTenSum(n);
}