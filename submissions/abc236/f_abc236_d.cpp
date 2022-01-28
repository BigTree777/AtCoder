#include<bits/stdc++.h>
using namespace std;

pair<int, int> select(map<int, int>& used, int N){
    for(int i=0; i<N; i++){
        
       for(int j=i+1; j<N+1; j++){
            used[i] = j;
       } 
    }
}

int main(){
    int N;
    cin >> N;
    map<pair<int, int>, int> A;
    pair<int, int> p;
    for(int i=1; i<2*N+1; i++){
        for(int j=i+1; j<2*N+1; j++){
            p = make_pair(i, j);
            cin >> A[p];
        }
    }
    int loop = 0;
    int k = 2*N-1;
    while(k>0){
        k -= 2;
        loop += 1;
    }
    map<int, int> used;
    for(int i=0; i<loop; i++){
        
    }
    
    return 0;
}