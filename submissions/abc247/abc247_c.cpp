#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

string SN(int N){
    if(N == 1){
        return "1";
    }
    string n = to_string(N);
    return SN(N-1) + " " + n + " " + SN(N-1);
}

int main(){
    int N;
    cin >> N;

    cout << SN(N) << endl;
    return 0;
}