#include<bits/stdc++.h>

using namespace std;
	
int power(int a,int N){
	if(N<=1)
		return a;
	else
		return a * power(a,N-1);
}

int main(){
	cout << power(2,8);	
}
