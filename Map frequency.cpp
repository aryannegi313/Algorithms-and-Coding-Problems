#include<bits/stdc++.h>

using namespace std;

void freq(string F)
{
	map<char,int> frequency;
	
	for(int i = 0 ; i < F.length() - 1 ; i++)
	{
		if(frequency.find( F[i] ) == frequency.end()){
			frequency[F[i]] = 1;
		}
		
		else{
			frequency[F[i]]++;
		}
	}
	
	 map<char, int>::iterator itr;
	for(itr = frequency.begin() ; itr != frequency.end() ; itr++)
	{
		cout<< itr->first << " " << itr->second << "\n";
	}
}

int main(){
	
	string s = "sadfghjkljhgfdsasdfghj";
	
	freq(s);
}
