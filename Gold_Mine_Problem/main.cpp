#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int row, column;
	cout << "Enter row value: " << endl;
	cin >> row;
	cout << "Enter column value: " << endl;
	cin >> column;
	
	int mine[row][column]; //given matrix
	cout << "Enter the cell values: " << endl;
	for(int i = 0; i < row; i++){
		
		for(int j = 0; j < column; j++){
			
			cin >> mine[i][j];
		} 
	}
	int dp[row][column];
	
	for (int i = 0; i < row; i++) {
		
		dp[i][0] = mine[i][0];
	}
	
	for(int j = 1; j < column; j++){
		
		for(int i = 0; i < row; i++){
			
			if(i == 0){
				
				dp[i][j] = mine[i][j] + max(dp[i][j - 1], dp[i + 1][j - 1]);
			}else if(i == row - 1){
				
				dp[i][j] = mine[i][j] + max(dp[i][j - 1], dp[i - 1][j - 1]);
			}else{
				
				dp[i][j] = mine[i][j] + max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i + 1][j - 1]));
			}
		}
	}
	int max_gold = 0;
	for(int i = 0; i < row; i++){
		
		if(max_gold <= dp[i][column - 1]){
			
			max_gold = dp[i][column - 1];
		}
	}
	cout << max_gold << endl;
	
	
}
