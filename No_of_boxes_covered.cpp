#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int x1,y1,x2,y2;
    
    cin >> n >> x1 >> y1 >> x2 >> y2;
    
    int y = y2 - y1;
    int x = x2 - x1;
    
    float dist = sqrt(pow(y,2) + pow(x,2));
    
    cout<<floor(dist);
}