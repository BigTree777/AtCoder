// N回目に到達しうる位置の中にXが含まれているかを算出しようとしてしまった

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, X;
    cin >> N >> X;

    int a[N], b[N];
    for(int i=0; i<N; i++) cin >> a[i] >> b[i];

    int sum;
    vector<bool> checked(N, false);
    for(int i=0; i<N; i++){
        if(checked[i]) continue;
        sum += a[i];
        if(sum > X){
            sum -= a[i];
            sum += b[i];
            if(sum > X){
                sum -= b[i];
                sum -= a[i-1];
                checked[i] = true;
                i--;
            }
        }
        if(find(checked.begin(), checked.end(), false)==checked.end()) break;
    }
    return 0;
}