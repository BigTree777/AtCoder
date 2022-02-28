// f_abc241_c.cppを修正
// 斜めを右下がりでしか計算していなかった
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;
    vector<string> S(N, (string)".");
    for(int i = 0; i < N; i++) cin >> S[i];

    int count;
    bool six = false;
    for(int i = 0; i < N; i++){
        // row
        for(int j = 0; j < N; j++){
            if(j + 6 > N) break;
            count = 0;
            for(int k = 0; k < 6; k++){
                if(S[i][j+k] == '#'){
                    count += 1;
                    if(count == 4){
                        six = true;
                        break;
                    }
                }
            }
            if(six) break;
        }
        if(six) break;
        // culumn
        for(int j = 0; j < N; j++){
            if(j + 6 > N) break;
            count = 0;
            for(int k = 0; k < 6; k++){
                if(S[j+k][i] == '#'){
                    count += 1;
                    if(count == 4){
                        six = true;
                        break;
                    }
                }
            }
            if(six) break;
        }
        if(six) break;
        // slope +
        if(i + 6 <= N){
            for(int j = 0; j < N; j++){
                if(j + 6 > N) break;
                count = 0;
                for(int k = 0; k < 6; k++){
                    if(S[i+k][j+k] == '#'){
                        count += 1;
                        if(count == 4){
                            six = true;
                            break;
                        }
                    }
                }
                if(six) break;
            }
        }
        if(six) break;
        // slope -
        if(i - 6 >= -1){
            for(int j = 0 ; j < N; j++){
                // if(j - 6 < -1) break;
                if(j + 6 > N) break;
                count = 0;
                for(int k = 0; k < 6; k++){
                    if(S[i-k][j+k] == '#'){
                        count += 1;
                        if(count == 4){
                            six = true;
                            break;
                        }
                    }
                }
                if(six) break;
            }
            if(six) break;
        }
    }
    if(six) cout << "Yes" << endl;
    else cout << "No" << endl;   

    return 0;
}