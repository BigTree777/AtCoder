#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    vector<int> A(N, 0);
    int ans = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    for(int a: A){
        if(a >= 0){
            if(ans == a){
                ans += 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}