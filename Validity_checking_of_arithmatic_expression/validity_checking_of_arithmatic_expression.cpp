#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;
    stack<char> stk;
    if(!s.empty()){

        for(int i = 0; i < s.length(); i++){

            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }
            if((s[i] == ')' && stk.top() == '(') || (s[i] == '}' && stk.top() == '{') || (s[i] == ']' && stk.top() == '[')){

                stk.pop();
            }
        }
    }else{
        cout << "string empty" << endl;
    }

    if(stk.empty()){

        cout << "Yes" << endl;
    }else{

        cout << "No" << endl;
    }
}
