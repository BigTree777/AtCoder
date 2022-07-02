#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int K;
    cin >> K;

    if(K < 60){
        int H = 21;
        int M = K;
        cout << setw(2) << setfill('0') << H << ":";
        cout << setw(2) << setfill('0') << M << endl;
    }
    else{
        int H = 21 + 1;
        int M = K - 60;
        cout << setw(2) << setfill('0') << H << ":";
        cout << setw(2) << setfill('0') << M << endl;
    }

    return 0;
}