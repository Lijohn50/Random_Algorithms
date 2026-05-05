#include<bits/stdc++.h>
using namespace std;
int main(){
	
	string s1;
	string s2;
	
	cout << "Enter string 1: " << endl;
	cin >> s1;
	cout << "Enter string 2: " << endl;
	cin >> s2;
	
	int sol[s1.size() + 1][s2.size() + 1];
	for(int i = 0; i <= s1.size(); i++){
		
		for(int j = 0; j <= s2.size(); j++){
			
			if(i == 0 || j == 0){
				
				sol[i][j] = 0;
			}else{
				
				if(s1[i] == s2[j]){
					
					sol[i][j] = sol[i - 1][j - 1] + 1;
				}else{
					
					sol[i][j] = max(sol[i - 1][j], sol[i][j - 1]);
				}
			}
		}
	}
	cout << sol[s1.size()][s2.size()] << endl;
}
