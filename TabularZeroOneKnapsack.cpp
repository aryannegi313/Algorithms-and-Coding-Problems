#include<bits/stdc++.h>
using namespace std;

int zeroOneKnapsack(vector<int> wt,vector<int> val,int W){
    
    int n = wt.size();
    vector<vector<int>> table(n+1 , vector<int> (W+1, 0)); 
    
    for(int i=1;i<n+1;i++){
        for(int w=1;w<W+1;w++){
            if (wt[i - 1] <= w) {
                table[i][w] = max(val[i-1] + table[i-1][w-wt[i-1]], table[i-1][w]); 
            }
            else
                table[i][w] = table[i-1][w];
        }
    }
    
    int v = table[n][W];
    
    vector<int> included(n,1);
    for(int i=n-1;i>=0;i--){
        int flag = 1;
        for(int w=0;w<W+1;w++){
            if(table[i][w] == v){
                flag = 0;
                break;
            }
        }
        included[i] = flag;
        if(flag == 1)
            v = v - val[i];
    }
    
    for(int i=0;i<n;i++)
        cout<<included[i]<<" ";
    cout<<endl;
    return table[n][W];
}

int main(){
    vector<int> val{60,100,120}; 
    vector<int> wt{10,20,30}; 
    int W = 50; 
    
    cout << zeroOneKnapsack(wt, val, W); 
    return 0; 
}