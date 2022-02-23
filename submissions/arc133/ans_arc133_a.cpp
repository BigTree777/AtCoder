// source: https://atcoder.jp/contests/arc133/editorial/3284
// A[i] > A[i+1]を満たすものを探す -> 昇順でなくなる位置を探す -> A[i]を消去することで辞書順として小さくなる
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i=0; i<N; i++) cin >> A[i];

    int x = -1;
    for(int i=0; i<N; i++){
        if(A[i] > A[i+1]){
            x = A[i];
            break;
        }
    }

    if(x==-1) x = A[N-1];
    for(int i=0; i<N; i++){
        if(A[i]==x) continue;
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}