// 累積和を思いつくのに時間がかかった

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;
    int C[N+1], P[N+1];
    int one[N+1], two[N+1];
    one[0] = 0;
    two[0] = 0;
    for(int i = 1; i < N + 1; i++){
        cin >> C[i] >> P[i];
        if(C[i] == 1){
            one[i] = one[i-1] + P[i];
            two[i] = two[i-1];
        }
        else{
            one[i] = one[i-1];
            two[i] = two[i-1] + P[i];
        }
    }

    int Q;
    cin >> Q;
    int L, R;
    int A[Q], B[Q];
    for(int i = 0; i < Q; i++){
        cin >> L >> R;
        A[i] = one[R] - one[L-1];
        B[i] = two[R] - two[L-1];
    }
    for(int i = 0; i < Q; i++){
        cout << A[i] << " " << B[i] << endl;
    }
    return 0;
}