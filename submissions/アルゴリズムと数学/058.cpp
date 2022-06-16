#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, X, Y;
    cin >> N >> X >> Y;

    if(abs(X) + abs(Y) > N){
        cout << "No" << endl;
        return 0;
    }
    else{
        int c = (abs(X) + abs(Y)) % 2;
        int d = N % 2;
        if(c != d){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}