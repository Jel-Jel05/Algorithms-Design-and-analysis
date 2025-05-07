#include <iostream>
#include <vector>
using namespace std;



// NOT ENDED
int main(){
    int N, K, num;
    cin >> N >> K;
    vector<int> nums(N);
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < N; i++){
        cin >> num;
        if(num > K){
            num -= K;
            min = (num > min)? min:num;
            max = (num > max)? num:max;
        }
        else{
            num += K;
            min = (num > min)? min:num;
            max = (num > max)? num:max;
        }
        nums[i] = num;
    }

    cout << max - min;
}