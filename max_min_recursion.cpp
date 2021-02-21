#include<bits/stdc++.h>
using namespace std;

pair<int,int> min_max(vector<int> arr,int lb, int ub){
    pair<int,int> minmax,mml,mmr;
    
    if(ub == lb){
        minmax.first = arr[lb];
        minmax.second= arr[lb];
        return minmax;
    }
    if(ub-lb == 1)
    {
        if(arr[ub]>arr[lb]){
            minmax.first = arr[ub];
            minmax.second = arr[lb];
        }
        else{
            minmax.first = arr[lb];
            minmax.second = arr[ub];
        }
        
        return minmax;
    }
    int mid = (lb+ub)/2;
    mml = min_max(arr,lb,mid);
    mmr = min_max(arr,mid+1,ub);
    
    if(mml.first > mmr.first)
        minmax.first = mml.first;
    else
        minmax.first = mmr.first;
        
    if(mml.second < mmr.second)
        minmax.second = mml.second;
    else
        minmax.second = mmr.second;
        
    return minmax;
}

int main(){
    vector<int> arr{1,2,3,1,2,3,4,43,21,1,2};
    pair<int,int> minmax;
    minmax = min_max(arr,0,arr.size()-1);
    
    cout<<minmax.first <<" "<<minmax.second;
}