#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int l, int h){
    int pivot = arr[l];
    int i = l+1;
    int j = h-1;
    while(i<j){
        while(arr[i] <= pivot)
            i++;
        
        while(arr[j] > pivot)
            j--;
        
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[l];
    arr[l] = arr[j];
    arr[j] = arr[l];
    
    return j;
}

void quickSort(int *arr, int l, int h){
    while(l<h){
        int j = partition(arr,l,h);
        quickSort(arr, l , j);
        quickSort(arr, j+1, h);
    }
}

int main(){
    int arr[] = {1,4,1,2,3,4};
    
    quickSort(arr, 0, 6);
    
    for(int i=0;i<6;i++)
        cout<<arr[i];
}