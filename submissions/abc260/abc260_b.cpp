#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    vector<pair<int, int>> A(N), B(N), AB(N);

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp; // Math
        pair<int, int> p = make_pair(tmp, i+1);
        A[i] = p;
    }
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp; // English
        pair<int, int> p = make_pair(tmp, i+1);
        B[i] = p;
    }
    for(int i = 0; i < N; i++){
        pair<int, int> p = make_pair(A[i].first + B[i].first, i+1);
        AB[i] = p;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(AB.begin(), AB.end());

    vector<int> accept;
    int count = 0;
    int idx = N - 1;
    while(count < X){
        int tmp = idx;
        while(A[tmp-1].first == A[tmp].first){
            tmp--;
        }
        for(int i = tmp; i <= idx; i++){
            accept.push_back(A[i].second);
            count++;
            if(count >= X) break;
        }
        idx = tmp - 1;
    }
    count = 0;
    idx = N - 1;
    while(count < Y){
        int tmp = idx;
        while(B[tmp-1].first == B[tmp].first){
            tmp--;
        }
        for(int i = tmp; i <= idx; i++){
            if(find(accept.begin(), accept.end(), B[i].second) != accept.end()) continue;
            accept.push_back(B[i].second);
            count++;
            if(count >= Y) break;
        }
        idx = tmp - 1;
    }
    count = 0;
    idx = N - 1;
    while(count < Z){
        int tmp = idx;
        while(AB[tmp-1].first == AB[tmp].first){
            tmp--;
        }
        for(int i = tmp; i <= idx; i++){
            if(find(accept.begin(), accept.end(), AB[i].second) != accept.end()) continue;
            accept.push_back(AB[i].second);
            count++;
            if(count >= Z) break;
        }
        idx = tmp - 1;
    }
    sort(accept.begin(), accept.end());
    for(int a: accept){
        cout << a << endl;
    }
    
    return 0;
}