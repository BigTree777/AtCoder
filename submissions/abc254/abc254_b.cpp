#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    int output = 1;
    vector<int> vec[N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i+1; j++){
            if(j==0 || j==i){
                output = 1;
            }
            else{
                output = vec[i-1][j-1] + vec[i-1][j];
            }
            vec[i].push_back(output);
            cout << output << " ";
        }
        cout << endl;
    }

    return 0;
}