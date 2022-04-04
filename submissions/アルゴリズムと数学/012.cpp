#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll N;
    cin >> N;

    ll root = floor(pow(N, 0.5));
    for(ll i = 2; i <= root; i++){
        if(N % i == 0){
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}