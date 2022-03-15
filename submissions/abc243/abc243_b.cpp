#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    vector<int> A(N, 0), B(N, 0);
    map<int, int> mA, mB;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        mA[A[i]] = i;
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
        mB[B[i]] = i;
    }

    int sum_1 = 0, sum_2 = 0;
    for(int a: A){
        if(mB.find(a) == mB.end()) continue;
        if(mA[a] == mB[a]){
            sum_1 += 1;
            continue;
        }
        else{
            if(find(B.begin(), B.end(), a) != B.end()){
                sum_2 += 1;
            }
        }   
    }
    cout << sum_1 << endl;
    cout << sum_2 << endl;


    return 0;
}