#include<bits/stdc++.h>
using namespace std;
int main(){
	
	cout << "Enter total number of coins:" << endl;
	int n;
	cin >> n;
	
	int coins[n + 1];
	coins[0] = 0;
	for (int i = 1; i <= n; i++){
		
		cout << "Enter value of coin " << i << ": " << endl;
		cin >> coins[i];
	}
	cout << "Enter total amount to get from coins: " << endl;
	int amount;
	cin >> amount;
	int sol[n + 1][amount + 1];
	for(int i = 0; i <= n; i++){
		
		for (int j = 0; j <= amount; j++){
			
			if(i == 0 && j == 0){
				
				sol[i][j] = 1;
			}else if(i == 0){
				
				sol[i][j] = 0;
			}else{
				
				if(coins[i] > j){
					
					sol[i][j] = sol[i - 1][j];
				}else{
					
					sol[i][j] = sol[i - 1][j] + sol[i][j - coins[i]];
				}
			}
		}
	}
	cout << sol[n][amount] << endl;
}
