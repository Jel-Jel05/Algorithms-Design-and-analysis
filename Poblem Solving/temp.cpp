#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;


bool is_parenthesis(string s){
    stack <char> stk;
    for (char c : s){
        if(c =='('){
            stk.push('(');
        }
        else{
            if(stk.empty()){
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();    
}

int main(){
    cout << is_parenthesis("()()");
}