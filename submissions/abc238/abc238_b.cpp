#include<bits/stdc++.h>
#define MAX_DEG 360
using namespace std;


int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i=0; i<N; i++) cin >> A[i];

    deque<int> divide;
    divide.push_back(0);

    int a;
    for(int i=0; i<N; i++){
        a = A[i];
        // rot
        for(int j=0; j<divide.size(); j++){
            divide[j] += a;
            if(divide[j]>MAX_DEG) divide[j] -= MAX_DEG;
        }
        sort(divide.begin(), divide.end());
        // new
        divide.push_front(0);
    }

    int deg;
    int ans = 0;
    for(int j=0; j<divide.size(); j++){
        if(j==divide.size()-1) deg = MAX_DEG - divide[j];
        else deg = divide[j+1] - divide[j];
        if(deg > ans) ans = deg;
    }

    cout << ans << endl;
    return 0;
}