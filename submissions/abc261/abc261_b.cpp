#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    vector<char> A[N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char a;
            cin >> a;
            A[i].push_back(a);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                if(A[i][j] != '-'){
                    cout << "incorrect" << endl;
                    return 0;
                }
            }
            else{
                if((A[i][j] == 'W') && (A[j][i] != 'L')){
                    cout << "incorrect" << endl;
                    return 0;
                }
                else if((A[i][j] == 'L') && (A[j][i] != 'W')){
                    cout << "incorrect" << endl;
                    return 0;
                }
                else if((A[i][j] == 'D') && (A[j][i] != 'D')){
                    cout << "incorrect" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "correct" << endl;
    return 0;
}