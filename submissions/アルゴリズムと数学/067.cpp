#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int H, W;
    cin >> H >> W;

    vector<int> A[H];
    vector<int> a(W, 0);
    vector<int> sum_row(H, 0);
    vector<int> sum_col(W, 0);
    for(int i = 0; i < H; i++){
        A[i] = a;
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
            sum_row[i] += A[i][j];
            sum_col[j] += A[i][j];
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            int ans = sum_row[i] + sum_col[j] - A[i][j];
            cout << ans << " ";
        }
        cout << endl;
     }
    return 0;
}