#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, X;
    cin >> N >> X;

    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i = 0; i < 26; i++){
        if(X <= (i + 1) * N){
            cout << alpha[i] << endl;
            break;
        }
    }
    return 0;
}