#include <bits/stdc++.h>
using namespace std;

void anagramDict(vector<string> str){
    unordered_map<string,vector<string>> map;
    unordered_map<string,vector<string>>::iterator it;
    
    for(int i=0;i<str.size();i++){
        string tempStr(str[i]);
        sort(tempStr.begin(),tempStr.end());
        
        if(map.find(tempStr) == map.end()){
            vector<string> tempVector;
            tempVector.push_back(str[i]);
            map.insert(make_pair(tempStr,tempVector));
        }
        
        else{
            vector<string> tempVector(map[tempStr]);
            tempVector.push_back(str[i]);
            map[tempStr] = tempVector;
        }
    }
    
    for(it=map.begin();it!=map.end();it++){
        vector<string> temp(it->second);
        for(int i=0;i<temp.size();i++)
            cout<<temp[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n; //number of strings;
    vector<string> str(n);
    
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    
    anagramDict(str);
    
}
