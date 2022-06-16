#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    string N;
    cin >> N;

    if(N.size() == 2){
        cout << N << endl;
        return 0;
    }
    else{
        cout << N.substr(1, 2) << endl;
    }
    return 0;
}