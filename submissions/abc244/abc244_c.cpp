#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    int A[2*N+2];
    for(int i = 0; i < 2*N+2; i++){
        A[i] = i;
    }
    A[0] = -1;
    bool game = true;
    int b;
    while(game){
        for(int i = 0; i < 2*N+2; i++){
            if(A[i] != -1){
                cout << A[i] << endl;
                A[i] = -1;
                game = true;
                break;
            }
            else{
                game = false;
            }
        }
        cin >> b;
        if(b == 0){
            game = false;
        }
        else{
            A[b] = -1;
        }
    }
    
    return 0;
}