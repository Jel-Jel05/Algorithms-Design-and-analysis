#include <iostream>
#include <string>
using namespace std;

bool check_palindromic(string s){
    int i = 0, j = s.length()-1;
    while (j > i){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void palindromic(string s, string sub_s, int iterator ,int &max, string &ans){
    if(iterator == s.length()){
        return;
    }
    if(sub_s.length() > 0 && check_palindromic(sub_s)){
        if(sub_s.length() > max){
            max = sub_s.length();
            ans = sub_s;
        }
    }

    sub_s.push_back(s[iterator]);
    palindromic(s, sub_s, iterator + 1, max, ans);
    sub_s.pop_back();
    palindromic(s, sub_s, iterator + 1, max, ans);
}


int main(){
    string s, sub_s = "", ans = "";
    cin >> s;
    int max = 0;
    palindromic(s, sub_s, 0, max, ans);
    cout << ans;
    
}