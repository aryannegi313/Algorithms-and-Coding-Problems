#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int m;
    cin >> m;
    int count = 0;
    
    while(m!=0){
        if(m>=1 && m<5){
            count++;
            m = m-1;
        }
        
        else if(m>=5 && m<10){
            count++;
            m = m-5;
        }
        
        else if(m>=10){
            count++;
            m = m-10;
        }
        
        else{
            count = 0;
        }
    }
    
    cout << count;
}