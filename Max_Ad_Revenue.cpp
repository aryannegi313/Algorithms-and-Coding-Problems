#include<bits/stdc++.h>

using namespace std;

int newSol(vector<int> profit,vector<int> clicks,int n){
    
    sort(profit.begin(),profit.end());
    int max;
    int sum = 0;
    
    // for(int i=0;i<n;i++)
    //     cout<<profit[i];
    
    for(int i=n-1;i>=0;i--){
        max = INT_MIN;
        for(int j=0;j<clicks.size();j++){
            if((profit[i]*clicks[j])>max){
                max = profit[i]*clicks[j];
                //cout<<clicks[j];
                clicks.erase(clicks.begin() + j);
            }
            cout<<max<<endl;
        }
        sum = sum + max;
    }
    return sum;
}

int main(){
    
    int n,j=0,sum;
    cin >> n;
    vector<int> profit(n),clicks(n);
    
    // while(j<=30){
    //     n = rand() % 5 + 1;
        
    //     vector<int> profit(n),clicks(n);
    //     cout<<n<<endl;
        
    //     for(int i=0;i<n;i++){
    //         profit[i] = rand() % 10 - 5;
    //         cout << profit[i] << " ";
    //     }
        
    //     cout<<endl;
        
    //     for(int i=0;i<n;i++){
    //         clicks[i] = rand() % 10 - 7;
    //         cout << clicks[i] << " ";
    //     }
        
    //     sort(profit.begin(),profit.end());
    //     sort(clicks.begin(),clicks.end());
        
    //     cout<<endl<<"sorted:"<<endl;
        
    //     for(int i=0;i<n;i++)
    //         cout << profit[i] << " ";
        
    //     cout<<endl;
        
    //     for(int i=0;i<n;i++)
    //         cout << clicks[i] << " ";
        
    //     cout<<endl<<"sums:"<<endl;
    //     sum =0;
    //     for(int i=0;i<n;i++){
    //         sum = sum + profit[i] * clicks[i];
    //         cout<<sum<<endl;
    //     }
        
    //     cout<<sum<<endl<<endl;
    //     j++;
    // }
    
    for(int i=0;i<n;i++)
        cin >> profit[i];
    
    for(int i=0;i<n;i++)
        cin >> clicks[i];
    
    cout<<newSol(profit,clicks,n);
    
    // sort(profit.begin(),profit.end());
    // sort(clicks.begin(),clicks.end());
    
    // int sum = 0;
    // for(int i=0;i<n;i++)
    //     sum = sum + profit[i] * clicks[i];
        
    // cout<<sum;
}
