#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    int L[N], R[N];
    for(int i = 0; i < N; i++) cin >> L[i] >> R[i];

    vector<int> X, Y;
    X.push_back(L[0]);
    Y.push_back(R[0]);
    for(int i = 1; i < N; i++){
        int num = X.size();
        for(int j = 0; j < num; j++){
            if(X[j] > R[i] || Y[j] < L[i]){
                X.push_back(L[i]);
                Y.push_back(R[i]);
            }
            else if(X[j] <= L[i] && Y[j] <= R[i]){
                Y[j] = R[i];
            }
            else if(X[j] >= L[i] && Y[j] >= R[i]){
                X[j] = L[i];
            }
            else if(X[j] >= L[i] && Y[j] <= R[i]){
                X[j] = L[i];
                Y[j] = R[i];
            }
        }
    }
    assert(X.size() == Y.size());
    for(int i = 0; i < X.size(); i++)  cout << X[i] << " " << Y[i] << endl;
    return 0;
}