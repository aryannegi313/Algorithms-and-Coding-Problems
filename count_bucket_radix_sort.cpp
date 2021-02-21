#include<bits/stdc++.h>
using namespace std;

int get_max(vector<int> arr){
    int max = arr[0];
    
    for(int i =0; i<arr.size();i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }   
    
    return max;
}
 
vector<int> countSort(vector <int> arr)
{
    int max = get_max(arr);
    vector<int> count(max+1), output(arr.size());
    
    for(int i = 0; i < arr.size(); i++)
        count[arr[i]]++;
          
    for(int i = 1; i < count.size(); i++)
           count[i] += count[i-1];
    
    for(int i = arr.size()-1; i >= 0; i--)
    {  
         output[count[arr[i]] -1 ] = arr[i];  
              count[arr[i]]--;  
    }
      
    for(int i=0; i < arr.size(); i++)
            arr[i] = output[i];
            
    return arr;
}

vector<int> countSortForRadix(vector<int> arr,int exp)
{
    int output[arr.size()];
    int i;
    vector<int> count(10);
    int n = arr.size();
 
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
        
    return arr;
}

vector<int> radixsort(vector<int> arr)
{
    int m = get_max(arr);
 
    for (int exp = 1; m/exp > 0; exp *= 10)
        arr = countSortForRadix(arr, exp);
    
    return arr;
}

float* bucketSort(float arr[],int n)
{
    vector<float> b[n];
     
    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i];
       b[bi].push_back(arr[i]);
    }
 
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];

    return arr;
}

int main(){
    
    int n,choice;
    cout<<endl<<"For count sort press 1 for radix sort press 2 and for bucket press 3:"<<endl;
    cin>>choice;
    
    if(choice == 1){
        cout<<"enter the size of the array:"<<endl;
        cin>> n;
    
        vector<int> arr(n);
        cout<<endl<<"enter the array:"<<endl;
        for(int i=0;i<n;i++)
            cin>>arr[i];
    
        arr = countSort(arr);
        
        for(int i=0; i<n; i++)
            cout << arr[i] << " ";
    }
    else if(choice == 2)
    {
        cout<<"enter the size of the array:"<<endl;
        cin>> n;
    
        vector<int> arr(n);
        cout<<endl<<"enter the array:"<<endl;
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        arr = radixsort(arr);
        
        for(int i=0; i<n; i++)
            cout << arr[i] << " ";
    }
    else if(choice == 3)
    {
        cout<<"enter the size of the array:"<<endl;
        cin>> n;
    
        float *arr = new float[n];
        cout<<endl<<"enter the array:"<<endl;
        for(int i=0;i<n;i++)
            cin>>arr[i];
    
        arr = bucketSort(arr,n);
        
        for(int i=0; i<n; i++)
            cout << arr[i] << " ";
    }   
}
