#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N, 0);
    int B[M];
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    bool success;
    for(int i = 0; i < M; i++){
        success = false;
        if(A.size()==0) break;
        for(vector<int>::iterator j = A.begin(); j != A.end(); j++){
            if(B[i] == *j){
                success = true;
                A.erase(j, j+1);
                break;
            }
        }
        if(!success) break;
    }
    if(success) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}