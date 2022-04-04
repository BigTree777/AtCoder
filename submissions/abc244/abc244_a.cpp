#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    vector<int> x(3, 0), y(3, 0);
    for(int i = 0; i < 3; i++){
        cin >> x[i] >> y[i];
    }

    int ax, ay;
    if(find(x.begin()+1, x.end(), x[0]) == x.end()) ax = x[0];
    else if(find(x.begin()+1, x.end(), x[0]) == x.begin()+1) ax = x[2];
    else ax = x[1];
    if(find(y.begin()+1, y.end(), y[0]) == y.end()) ay = y[0];
    else if(find(y.begin()+1, y.end(), y[0]) == y.begin()+1) ay = y[2];
    else ay = y[1];

    cout << ax << " " << ay << endl;
    
    return 0;
}