#include <iostream>
#include <vector>
using namespace std;

void largest_sub_sum(int size, int iterator, vector<int> &arr, vector<int> &temp, vector<int> &ans, int max, vector<vector<int>> &test){
    if(iterator == size){
        return;
    }

    if(temp.size()){
        int sum = 0;
        test.push_back(temp);
        for(int i = 0; i < temp.size(); i++){
            sum += temp[i];
        }
        if(sum > max){
            max = sum;
            ans = temp;
        }
    }

    largest_sub_sum(size, iterator+1, arr, temp, ans, max, test);
    temp.push_back(arr[iterator]);
    largest_sub_sum(size, iterator+1, arr, temp, ans, max, test);
    temp.pop_back();
    
}


int main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> ans, temp; vector<vector<int>> test; int sum = 0;
    largest_sub_sum(arr.size(), 0, arr, temp, ans, sum, test);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    // for(int i = 0; i < test.size(); i++){
    //     for(int j = 0; j < test[i].size(); j++){
    //         cout << test[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << endl << sum;
    return 0;
}