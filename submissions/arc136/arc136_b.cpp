// 交換の仕方によって配列そのものが変化する -> 題意を満たすときの条件がわからない
//
//

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool judge(int N, int A[], int B[]){
    for(int i = 0; i < N; i++){
        if(A[i] == B[i]) continue;
        else return false;
    }
    return true;
}

map<int, vector<int>> search(int N, int A[], int B[]){
    map<int, vector<int>> map0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(B[i] == A[j]){
                map0[B[i]].push_back(j);
            }
        }
    }
    for(int i = 0; i < N; i++){
        int b = B[i];
        if(map0[b].size() == 0){
            map0.clear();
        }
    }
    return map0;
}
void exchange(int A[], int start){
    int a0, a1, a2;
    a0 = A[start];
    a1 = A[start+1];
    a2 = A[start+2];
    A[start] = a2;
    A[start+1] = a0;
    A[start+2] = a1;
}

int main(){
    int N;
    cin >> N;
    int A[N], B[N];
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    if(judge(N, A, B)){
        cout << "Yes" << endl;
        return 0;
    }

    map<int, vector<int>> m = search(N, A, B);
    if(m.empty()){
        cout << "No" << endl;
        return 0;
    }
    bool ac = true;
    vector<int> vec;
    int move;
    for(int i = 0; i < N; i++){
        vec = m[B[i]];
        for(int v: vec){
            move = v - i;
            int start = v - 2;
            if(move < 0) continue;
            if(move%2 == 0){
                for(int j = 0; j < move*0.5; j++){
                    exchange(A, start);
                    start -= 2;
                }
            }
            else{
                for(int j = 0; j < floor(move*0.5); j++){
                    exchange(A, start);
                    start -= 2;
                }
                start -= 1;
                exchange(A, start);  exchange(A, start);
            }
            
        } 
    }
    return 0;
}