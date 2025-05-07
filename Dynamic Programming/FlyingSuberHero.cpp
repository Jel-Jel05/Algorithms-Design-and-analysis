#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
int min_energy(vector<int>& buildings, int n, int iterator){
    if (iterator >= n){
        return 0;
    }

    if (dp[iterator] != -1) return dp[iterator];

    int take_next = min_energy(buildings, n, iterator + 1) + buildings[iterator];
    int skip_next = min_energy(buildings, n, iterator + 2) + buildings[iterator];;
    return dp[iterator] = min(take_next , skip_next);
}

int main(){
    int n;
    cin >> n;
    vector<int> buildings(n);
    for(int i = 0; i < n; i++){
        cin >> buildings[i];
    }
    if(n == 1){
        cout << buildings[0];
    }
    dp.assign(n+1, -1);
    cout << min(min_energy(buildings, n, 0), min_energy(buildings, n, 1));
}