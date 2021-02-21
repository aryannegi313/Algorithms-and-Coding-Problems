#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int n,W;
    cin >> n >> W;
    int v,w;
    vector<pair<double,pair<int,int>>> fractions;
    
    for(int i=0;i<n;i++){
        cin >> v >> w;
        fractions.push_back( make_pair( (double) v/w , make_pair(v,w) ) );
    }
    
    sort(fractions.begin(),fractions.end());
    double value = 0.000;
    
    int i = n-1;
    while(i>=0 && W>0){
        if(fractions[i].second.second < W){
            W = W - fractions[i].second.second;
            value = value + (double)fractions[i].second.first;
        }
        else{
            value = value + fractions[i].second.first*((double)W/fractions[i].second.second);
            W = W - fractions[i].second.second;
        }
        i--;
    }
    
    printf("%.3lf",value);
}