#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int A, B;
    cin >> A >> B;

    float sql = sqrt(pow(A, 2) + pow(B, 2));
    float x = (float)A / sql;
    float y = (float)B / sql;
    cout << x << " " << y << endl;

    return 0;
}