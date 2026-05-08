#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int row, column;
	cout << "Enter the Row and Column" << endl;
	cin >> row >> column;
	
	int grid[row][column];
	cout << "Enter the grid values: " << endl;
	for(int i = 0; i < row; i++){
		
		for(int j = 0; j < column; j++){
			
			cin >> grid[i][j];
		}
	}
	
	int dp[row][column];
	dp[0][0] = grid[0][0];
	for(int i = 1; i < row; i++){
		
		dp[i][0] = grid[i][0] + dp[i - 1][0]; 
	}
	for(int i = 1; i < column; i++){
		
		dp[0][i] = grid[0][i] + dp[0][i - 1];
	}
	
	for(int i = 1; i < row; i++){
		
		for(int j = 1; j < column; j++){
			
			dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	
	for(int i = 0; i < row; i++){
		
		for(int j = 0; j < column; j++){
			
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	int i = row - 1;
	int j = column - 1;
	vector<int> original_path;
	
	while(j >= 0 && i >= 0){
		
		original_path.push_back(grid[i][j]);
		if(i == 0){
			
			j--;
		}else if(j == 0){
			
			i--;
		}else if(dp[i - 1][j] < dp[i][j - 1]){
			
			i--;
		}else{
			
			j--;
		}
		
		cout << i << " " << j << endl;
	}
	for(int i = 0; i < original_path.size(); i++){
		
		cout << original_path[i] << endl;
	}
}

