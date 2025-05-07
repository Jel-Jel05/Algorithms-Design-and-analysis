#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n));
    array <int, 2>ans = {0, 0};

    //step1: all chars is palindrome to itself, so we will store it in the dp with dp[i][i] to be true 
    for(int i = 0; i < n; i++){
        dp[i][i] = true;
    }

    //step2: check if the adjacent chars is palindrome or not
    for(int i = 0; i < n; i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = true;
            ans = {i, i+1};
        }
    }

    /*step3: get into the general case
        now we have informations about all distinct ans every adjacent chars that is pali or not
        so we will start with sub_arr of size 3 and check if its elements is palindrome or not, by checking first and last element in sub_arr
        and the sub_arr between them.
        say i = 3 and j = 6
        so we check if s[i] == s[j] if true -----> check if sub_arr[4][5] is valid or not from the previous computations and so on.......
    */
    int j = 0;
    for(int diff = 2; diff < n; diff++){
        for (int i = 0; i < n - diff; i++){
            j = i + diff;
            if(s[i] == s[j] && dp[i+1][j-1]){
                dp[i][j] = true; // mark the new valid sub_arr to be true and use it again if we want to do it. 
                ans = {i, j};
            }
        }
    }
    cout << s.substr(ans[0], ans[1] - ans[0] + 1);

}