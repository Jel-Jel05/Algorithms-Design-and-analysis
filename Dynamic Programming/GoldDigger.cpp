#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
int gold_digger(vector<int>& chests, int n, int iterator){
    if(iterator >= n){
        return 0;
    }

    if(dp[iterator] != -1) return dp[iterator];

    int take = gold_digger(chests, n, iterator+2) + chests[iterator];
    int skip = gold_digger(chests, n, iterator+1);

    return dp[iterator] = max(take, skip);
}

int main(){
    int n;
    cin >> n;
    vector<int> chests(n);
    for (int i = 0; i < n; i++){
        cin >> chests[i];
    }
    dp.assign(n, -1);
    cout << gold_digger(chests, n, 0);
}