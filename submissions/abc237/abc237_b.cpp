#include<bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    map<int, vector<int>> A;
    vector<int> base(W, 0);
    for(int i=0; i<H; i++){
        A[i] = base;
        for(int j=0; j<W; j++){
            cin >> A[i][j];
        }
    }

    for(int i=0; i<W; i++){
        for(int j=0; j<H; j++){
            cout << A[j][i];
            if(j==H-1) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}