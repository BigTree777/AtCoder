#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, K, Q;
    cin >> N >> K >> Q;

    int A[K+1];
    for(int i = 1; i < K+1; i++) cin >> A[i];

    int L[Q+1];
    for(int i = 1; i < Q+1; i++) cin >> L[i];

    vector<bool> vec(N+1, false);
    vec[0] = false;

    for(int i = 1; i < K+1; i++){
        vec[A[i]] = true;
    }
    for(int i = 1; i < Q+1; i++){
        int pos = A[L[i]]; // 左からL番目[i]のコマの位置
        if(pos == N){
            continue;
        }
        if(vec[pos+1] == false){
            vec[pos] = false;
            vec[pos+1] = true;
            A[L[i]] = pos + 1;
        }
    }

    for(int i = 1; i < N+1; i++){
        if(vec[i] == true) cout << i << " ";
    }
    cout << endl;
    return 0;
}