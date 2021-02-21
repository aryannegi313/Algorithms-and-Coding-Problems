#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> arr,int l, int h){
    
    int pivot = arr[h];
    int i = (l - 1); 
  
    for (int j = l; j <= h - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++;
            int temp = arr[i]; 
            arr[i] = arr[j];
            arr[j] = temp;
        }  
    }  
    int temp = arr[i+1]; 
    arr[i+1] = arr[h];
    arr[h] = temp;
 
    return i+1;   
}

int main(){
    vector<int> arr{1,2,3,4,2,7,1};
    stack<pair<int,int>> bound;
    
    int lb = 0;
    int ub = arr.size()-1;
    
    bound.push(make_pair(lb , ub));
    
    while(!bound.empty()){
        
        lb = bound.top().first;
        ub = bound.top().second;
        bound.pop();
        int j = partition(arr,lb,ub);
        
        if(j-1 > 0)
            bound.push(make_pair(lb, j-1));
        
        if(j+1 < 0)
            bound.push(make_pair(j+1, ub));
    }
    
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i];
    }
}