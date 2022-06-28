#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int h[3], w[3];
    for(int i = 0; i < 3; i++){
        cin >> h[i] >> w[i];
    }

    vector<int> sum[3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            sum[i][j] = h[i] + w[j];
        }
    }

    vector<vector<int>> cand[3];
    vector<vector<int>> vec(3, vector<int>());
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 1; k < 10; k++){
                if(sum[i][j]-k > 4) cand[i][j].push_back(k);
            }
        }
    }

    return 0;
}