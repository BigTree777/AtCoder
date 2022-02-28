// 問題なく解けた

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int H, W;
    cin >> H >> W;

    vector<int> vec(W, 0);
    vector<vector<int>> A(H, vec);
    vector<vector<int>> ans(H, vec);
    vector<int> sum_line(H, 0);
    vector<int> sum_culumn(W, 0);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
            sum_line[i] += A[i][j];
            sum_culumn[j] += A[i][j];
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            ans[i][j] = sum_line[i] + sum_culumn[j] - A[i][j];
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}