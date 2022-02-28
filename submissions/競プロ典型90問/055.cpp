// 定数倍を考えることで計算量を見積もる


#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, P, Q;
    cin >> N >> P >> Q;

    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                for(int l = 0; l < k; l++){
                    for(int m = 0; m < l; m++){
                        int a = A[i] % P;
                        a %= P;
                        a *= A[j];
                        a %= P;
                        a *= A[k];
                        a %= P;
                        a *= A[l];
                        a %= P;
                        a *= A[m];
                        if(a % P == Q) ans += 1;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}