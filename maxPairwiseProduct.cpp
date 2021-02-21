#include <bits/stdc++.h>
using namespace std;

long long maxpairwiseproduct(vector<int> arr){
    long long result = 0;
    int n = arr.size();
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((long long) arr[i] * arr[j] > result)
                result = (long long) arr[i] * arr[j];
        }
    }    
    return result;
}

long long maxpairwiseproductfast(vector<int> arr){
    long long result = 0;
    int n = arr.size();
    int max1=0;
    int max2 = 0;
    int index =0 ;
    
    for(int i=0;i<n;i++){
        if(arr[i] > max1){
            max1 = arr[i];
            index = i;
        }
    }   
    
    for(int i=0;i<n;i++){
        if(arr[i] > max2 && i != index)
            max2 = arr[i];
    }

    
    result = (long long)max1 * max2;
    return result;
}

int main(){
    // while(true){
    //     int n = rand() % 98 + 2;
    //     cout << n << endl;
        
    //     vector<int> arr;
    //     for(int i =0; i<n;i++){
    //         arr.push_back(rand() % 100000);
    //         cout << arr[i] << ' ';
    //     }
        
    //     long long res1 = maxpairwiseproduct(arr);
    //     long long res2 = maxpairwiseproductfast(arr);
        
    //     if(res1 != res2){
    //         cout << endl <<"Wrong Answer "<<res1<<" "<<res2<<endl<<endl;
    //         break;
    //     }
    //     else
    //         cout<<"\nokay\n\n";
    //  }
    int n; 
    cin >> n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    cout << maxpairwiseproductfast(arr);
}