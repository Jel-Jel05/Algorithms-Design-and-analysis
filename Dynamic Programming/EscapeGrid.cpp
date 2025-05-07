#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<long long>>> dp(71, vector<vector<long long>>(71, vector<long long>(101, -1)));
long long escape( vector<vector<int>> &moves, int n, int k, int r, int cur_step, int x, int y){
    if(cur_step > k){
        return 0;
    }
    if(x < 0 || x >= n || y < 0 || y >= n) return 1;

    if(dp[x][y][cur_step] != -1) return dp[x][y][cur_step];

    long long sum = 0;
    for(int i = 0; i < r; i++){
        sum +=  escape(moves, n, k, r, cur_step + 1, x + moves[i][0], y + moves[i][1]);
    }

    return dp[x][y][cur_step] = sum;
}

int main(){
    int n, k, r, x, y;
    cin >> n >> k >> r >> x >> y;
    vector<vector<int>> moves(r, vector<int>(2));
    for (int i = 0; i < r; i++){
        cin >> moves[i][0] >> moves[i][1];
    }

    cout << escape(moves, n, k, r, 0, x, y);
}