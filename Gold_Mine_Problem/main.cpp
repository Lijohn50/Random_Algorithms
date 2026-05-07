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
	int position;
	for(int i = 0; i < row; i++){
		
		if(max_gold <= dp[i][column - 1]){
			
			max_gold = dp[i][column - 1];
			position = i;
		}
	}
	cout << max_gold << endl;
	
	int j = column - 2;
	int path[column];
	path[column - 1] = dp[position][column - 1];

	int path_row[column];
	int path_column[column];
	
	int r = column - 1;
	int c = column - 1;
	
	path_row[r] = position;
	path_column[c] = c;
	
	while(j >= 0){
		
		if(position == 0){
			
			path[j] = max(dp[position][j], dp[position + 1][j]);
			if(path[j] == dp[position][j]){
				
				r--;
				c--;
				path_row[r] = position;
				path_column[c] = j;
				j--;
			}else{
				
				r--;
				c--;
				path_row[r] = position + 1;
				path_column[c] = j;
				position++;
				j--;
			}
		}else if(position == row - 1){
			
			path[j] = max(dp[position][j], dp[position - 1][j]);
			if(path[j] == dp[position][j]){
				
				r--;
				c--;
				path_row[r] = position;
				path_column[c] = j;
				j--;
			}else{
				
				r--;
				c--;
				path_row[r] = position - 1;
				path_column[c] = j;
				position--;
				j--;
			}
		}else{
			
			path[j] = max(dp[position - 1][j], max(dp[position][j], dp[position + 1][j]));
			if(path[j] == dp[position - 1][j]){
				
				r--;
				c--;
				path_row[r] = position - 1;
				path_column[c] = j;
				position--;
				j--;
			}else if(path[j] == dp[position][j]){
				
				r--;
				c--;
				path_row[r] = position;
				path_column[c] = j;
				j--;
			}else if(path[j] == dp[position + 1][j]){
				
				r--;
				c--;
				path_row[r] = position + 1;
				path_column[c] = j;
				position++;
				j--;
			}
		}
	}
	
	for(int i = 0; i < column; i++){
		
		cout << mine[path_row[i]][path_column[i]] << endl;
	}

}
