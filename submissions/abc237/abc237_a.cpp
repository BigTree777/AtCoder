#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    ll min_N = -pow(2, 31);
    ll max_N = pow(2, 31);
    if((N>=min_N)&&(N<max_N)){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0;
}