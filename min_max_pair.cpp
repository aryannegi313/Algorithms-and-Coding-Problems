#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int max,min,n;
    
    vector<int> arr{-3,3,2,34,12,22,10,-22,8};
    
    if(arr.size() % 2 == 0){
        if(arr[0]>arr[1]){
            max = arr[0];
            min = arr[1];
        }
        else{
            max = arr[1];
            min = arr[0];
        }
        n = 2;
    }
    else{
        max = min = arr[0];
        n = 1;
    }
        
    for(int i = arr.size()-1 ; i >= n ; i = i-2){
        int mx,mn;
        
        if(arr[i] > arr[i-1]){
            mx = arr[i];
            mn = arr[i-1];
        }
        else{
            mx = arr[i-1];
            mn = arr[i];
        }
        
        if(max < mx)
            max = mx;
        if(min > mn)
            min = mn;
    }
    
    cout<<min << " "<< max;
}