#include<bits/stdc++.h>
using namespace std;

int power(int n,int m){
	
	if(m==0)
		return 1;
	
	else if(m==1)
		return n;
	else 
	{
		int R = power(n,m/2);
		if(m%2 == 0)	
			return R*R;
	
		else
			return R*n*R;
	}
}

int main(){
	cout << power(2,8);
}
