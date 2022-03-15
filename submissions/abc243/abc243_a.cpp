#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int V, A, B, C;
    cin >> V >> A >> B >> C;

    int i = 0, d;
    while(V >= 0){
        d = i % 3;
        switch (d)
        {
        case 0:
            V -= A;
            break;
        case 1:
            V -= B;
            break;
        case 2:
            V -= C;
            break;
        default:
            break;
        }
        if(V >= 0) i += 1;
    }
    if(i%3 == 0) cout << "F" << endl;
    else if(i%3 == 1) cout << "M" << endl;
    else cout << "T" << endl;

    return 0;
}