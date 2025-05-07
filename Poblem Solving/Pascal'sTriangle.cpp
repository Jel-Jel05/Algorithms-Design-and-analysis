#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    ans[0].push_back(1);
    for(int i = 1; i < numRows; i++){
        for(int j = 0; j < i+1; j++){
            if(j-1 < 0){
                ans[i].push_back(ans[i-1][j]);
            }
            else if(j == i){
                ans[i].push_back(ans[i-1][j-1]);
            }
            else ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
        }
    }
    return ans;
}

int main(){
    int n = 5;
    vector<vector<int>> ans = generate(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
        
    }
    
}