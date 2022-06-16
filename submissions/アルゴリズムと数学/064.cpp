#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    uint N, K;
    cin >> N >> K;

    uint A[N];
    for(int i = 0; i < N; i++) cin >> A[i];

    uint sum = 0;
    for(int i = 0; i < N; i++) sum += A[i];

    if(sum > K){
        cout << "No" << endl;
        return 0;
    }
    if(sum % 2 != K % 2){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}