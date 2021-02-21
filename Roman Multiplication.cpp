#include <bits/stdc++.h>
using namespace std;

int RomanToInt(char a)
{
    if(a=='I')
        return 1;
    else if(a=='V')
        return 5;
    else if(a=='X')
        return 10;
    else if(a=='L')
        return 50;
    else if(a=='C')
        return 100;
    else if(a=='D')
        return 500;
    else
        return 1000;
}

int CompleteRomanToNumber(string Roman){
    int len = Roman.length() - 1;
    int c=RomanToInt(Roman[len]);
    int sum = c;
    
    for(int i = len - 1; i >= 0 ; i--)
    {
        if( RomanToInt(Roman[i]) < c )
        {
            c = RomanToInt(Roman[i]);
            sum = sum - c;
        }
        else
        {
            c = RomanToInt(Roman[i]);
            sum = sum + c;
        }
    }
    
    return sum;
}

int main()
{
    string str1;
    string str2;
    
    cout << "Enter the Two Strings:";
    getline(cin,str1);
    getline(cin,str2);
    
    cout << CompleteRomanToNumber(str1) * CompleteRomanToNumber(str2);
    return 0;
}
