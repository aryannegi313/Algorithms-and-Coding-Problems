#include<bits/stdc++.h>
using namespace std;

int main(){
    int d,m,n,current_station,count = 0;
    cin>>d>>m>>n;
    
    int station[n+2];
    station[0] = 0;
    
    for(int i=1;i<=n;i++)
        cin>>station[i];
    
    station[n+1] = d;
    
    int i = 0;
    while(i<=n){
        current_station  = i;
        while( station[i+1]-station[current_station] <= m && i<=n)
            i++;
        
        if(current_station == i){
            count =-1;
            // cout<<"KFsdjk";
            break;
        }
        
        if(i<=n)
            count++;
        // cout<<i<<" "<<current_station<<" "<<count<<endl;
    }
    cout << count;
}