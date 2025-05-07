#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector <string> dp;
    dp.push_back("");
    for(int i = 0; i < 2*n; i++){
        string s = "";
        for (int j = 0; j < i ; j++){
            s = "(" + dp[j] + ")" + dp[i - j - 1];
            dp.push_back(s);
        }
    }

    for (int i = 1; i < dp.size(); i++){
        if(dp[i].size() == 2*n) cout << dp[i] << " ";
    }
}