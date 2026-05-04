#include<bits/stdc++.h>

using namespace std;

class process{
	
public:
	int process_id;
	int arrival_time;
	int burst_time;
	int turnaround_time;
	int completion_time;
	int waiting_time;
	int response_time;
};

int main(){
	
	int n;
	cout << "Enter amount of process: " << endl;
	cin >> n;
	process p[n];
	
	for(int i = 0; i < n; i++){
		
		p[i].process_id = i + 1;
		cout << "Enter process arrival time for process "<< i + 1 << ": " << endl;
		cin >> p[i].arrival_time;
		cout << "Enter process burst time for process " << i + 1 << ": " << endl;
		cin >> p[i].burst_time;
	}
	
	for(int i = 0; i < n - 1; i++){
		
		for(int j = 0; j < n - i - 1; j++){
			
			if(p[j].arrival_time >= p[j + 1].arrival_time){
				
				process temp;
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	
	int current_time = 0;
	for(int i = 0; i < n; i++){
			
		if(current_time < p[i].arrival_time){
			
			current_time = p[i].arrival_time;
		}
		
		p[i].response_time = current_time - p[i].arrival_time;
		current_time += p[i].burst_time;
		p[i].completion_time = current_time;
		p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
		p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
	}
	
	for(int i = 0; i < n; i++){
			
		cout << "process-" << p[i].process_id << " --- arrival_time[" << p[i].arrival_time << "] --- burst_time[" << p[i].burst_time << "] --- completion_time[" << p[i].completion_time << "] --- turnaround_time[" << p[i].turnaround_time << "] --- waiting_time[" << p[i].waiting_time << "] --- response_time[" << p[i].waiting_time << "]" << endl; 
	}	
}
