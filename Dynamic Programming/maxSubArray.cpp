#include <iostream>
#include <vector>
using namespace std;



int maxSubArray(vector<int>& nums) {
    int n = nums.size(), max = 1;
    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++){
        if(nums[i] > nums[i-1]){
            dp[i] += dp[i-1];
            if(dp[i] > max){
                max = dp[i];
            }
        }
    }
    return max;
}


int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(arr);
}