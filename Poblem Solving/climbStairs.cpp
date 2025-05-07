/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

In Dynamic programming, We have two solutions (Top Down memorization, Down Top memorization), Lets see how it works
*/

#include <iostream>
#include <unordered_map>
using namespace std;
 /* First Top Down memorization, in this solution we will move until we
found our target and in the way to find it we will collect the overladed solution that we calculated before*/

unordered_map<int, int> dp; // to mapping the discovered solutions.
int climb_stairs_upDown(int n){
    if(n <= 1){ // base condition
        return 1;
    }
    if(dp.find(n) != dp.end()) return dp[n]; // thats mean if we have calculated this solution before, then just return it, but if not ........
    dp[n] = climb_stairs_upDown(n-1) + climb_stairs_upDown(n-2); // calculate the mmissing solution and so on...
    return dp[n];
};


 /* second one is Down top memorization, in this sol we will calculate the solution from the leafs up to n
 such that every nth is calculated using previous n, lets see how to do that
 when we thinking about the problem we noticed that
 n = 0 -> sol = 0
 n = 1 -> sol = 1
 n = 2 -> sol = 3
 n = 3 -> sol = 4 (sol(2) + sol(1))
 n = 4 -> sol = 7 (sol(3) + sol (2))
 .
 .
 .
 .
 */

int climb_stairs_DownUp(int n){
    int *dp = new int[n+1];
    dp[0] = 0; dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= n; i++){ // Here we calculate all the solutions until we found our target(n) so we to get that we should get (n-1, n-2, n-3 , n-4, ...)
        dp[i] = dp[i-2] + dp[i-1];
    }
    int ans = dp[n];
    delete[] dp;
    return ans;
 }

 int main(){
    int n;
    cout << "Enter the number of staires: ";
    cin >> n;
    cout << "Solution using UpDown solution: " << climb_stairs_upDown(n) << endl;
    cout << "Solution using DownUp solution: " << climb_stairs_DownUp(n) << endl;
 }
