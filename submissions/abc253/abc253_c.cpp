#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ull N, A, B;
    cin >> N >> A >> B;

    double tmp = N * 0.5;
    tmp *= N + 1;
    ull total_sum = (ull)tmp;
    ull _min = min(A, B);
    ull i = 1;
    while(_min * i <= N){
        if(A * i <= N) total_sum -= A * i;
        if(B * i <= N) total_sum -= B * i;
        if(A * B * i <= N) total_sum += A * B * i;
        i++; 
    }
    cout << total_sum << endl;

    return 0;
}