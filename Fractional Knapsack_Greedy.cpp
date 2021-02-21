#include<bits/stdc++.h>
using namespace std;

int fractionalKnapsack(int m,vector<pair<int,int>> prob){
    vector<pair<double,pair<int,int>>> fractions;
    
    for(auto& i: prob)
        fractions.push_back(make_pair((double(i.second)/double(i.first)),make_pair(i.first,i.second)));
    
    sort(fractions.begin(),fractions.end());
    
    for(auto& i: fractions)
        cout<<i.second.first <<" "<< i.second.second << " "<< i.first<<endl;
    
    double profit = 0.0;
    int cur_weight = 0;
    for(int i= fractions.size()-1;i>=0;i--){
        if(cur_weight + fractions[i].second.first <= m){
            profit += fractions[i].second.second;
            cur_weight += fractions[i].second.first;
        }
        else{
            int remain = m - cur_weight;
            profit += fractions[i].second.second * ((double) remain / fractions[i].second.first); 
        }
    }
    
    return profit;
}

int main(){
    
    vector<pair<int,int>> prob = {{10, 60}, {20, 100}, {30, 120}};
    
    cout << fractionalKnapsack(50,prob);
}