    #include <iostream>
    #include <string>
    #include <stack>
    #include <vector>
    #include <chrono>
    using namespace std;

    bool is_parenthesis(string s){ //used to check the validity of the generated strings in the brute force solution
        stack <char> stk;
    for (char c : s){
        if(c =='('){
            stk.push('(');
        }
        else{
            if(stk.empty()){
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty(); 
    }

    void generate_parenthesis_BF(int n, int iterator, string s, vector<string> &ans){ // using brute force solution
        if(s.size() == 2 * n){
            if(is_parenthesis(s)){
                ans.push_back(s);
            }
            return;
        }

        if(iterator >= 2*n){
            return;
        }

        s.push_back('(');
        generate_parenthesis_BF(n, iterator + 1, s, ans);
        s.pop_back();

        s.push_back(')');
        generate_parenthesis_BF(n, iterator + 1, s, ans);
        s.pop_back();
    }

    void generate_parenthesis_BT(int n, string temp, vector<string> &ans, int open, int close){ //using back tracking solution
        if(temp.size() == 2*n){
            ans.push_back(temp);
            return;
        }
        
        if(open < n) generate_parenthesis_BT(n, temp + "(" , ans, open + 1, close);
        if(close < n) generate_parenthesis_BT(n, temp + ")", ans, open, close + 1);
    }

    int main(){
        int n, sol; cin >> n >> sol;
        vector<string> ans;
        auto start = std::chrono::high_resolution_clock::now();
        if(sol == 0){
            generate_parenthesis_BF(n, 0, "", ans);
        }else{
            generate_parenthesis_BT(n, "", ans, 0, 0);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;

        for (int i = 0; i < ans.size(); i++){
            cout << ans[i] << ", ";
        }
        cout << "\nExecution time of selected algorithm is: " << duration.count() << " sec \n";
    }