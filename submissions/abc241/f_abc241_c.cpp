// 考え方は正しそう
// WAになるパターンがわからない
// 重複箇所が多すぎた
// abc241_c.cppが修正版
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;
    // N = 1000;
    vector<string> S(N, (string)".");
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N - 1; j++){
    //         S[i] += '.';
    //     }
    // }
    for(int i = 0; i < N; i++) cin >> S[i];

    int count;
    // row
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j + 6 > N) break;
            count = 0;
            for(int k = j; k < j + 6; k++){
                if(S[i][k] == '#'){
                    count += 1;
                    if(count == 4) break;
                }
            }
            if(count == 4) break;
        }
        if(count == 4) break;
    }
    if(count == 4){
        cout << "Yes" << endl;
        return 0;
    }
    // culumn
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j + 6 > N) break;
            count = 0;
            for(int k = j; k < j + 6; k++){
                if(S[k][i] == '#'){
                    count += 1;
                    if(count == 4) break;
                }
            }
            if(count == 4) break;
        }
        if(count == 4) break;
    }
    if(count == 4){
        cout << "Yes" << endl;
        return 0;
    }
    // slope +
    for(int i = 0; i < N; i++){
        if(i + 6 > N) break;
        for(int j = 0; j < N; j++){
            if(j + 6 > N) break;
            count = 0;
            for(int k = 0; k < 6; k++){
                if(S[i+k][j+k] == '#'){
                    count += 1;
                    if(count == 4) break;
                }
            }
            if(count == 4) break;
        }
        if(count == 4) break;
    }
    if(count == 4){
        cout << "Yes" << endl;
        return 0;
    }
    // slope -
    for(int i = N - 1; i > -1; i--){
        if(i - 6 < -1) break;
        for(int j = N - 1 ; j > -1; j--){
            if(j - 6 < -1) break; // error
            count = 0;
            for(int k = 0; k < 6; k++){
                if(S[i-k][j-k] == '#'){ // error
                    count += 1;
                    if(count == 4) break;
                }
            }
            if(count == 4) break;
        }
        if(count == 4) break;
    }
    if(count == 4){
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;   

    return 0;
}