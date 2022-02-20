#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    bool aoki = false;
    bool tkhs = false;
    bool pn = true;
    int k_max;
    for(int i=A; i<=B; i++){
        tkhs = true;
        for(int j=C; j<=D; j++){
            k_max = i + j;
            pn = true;
            for(int k=2; k<k_max; k++){
                if(k_max%k==0){
                    pn = false;
                    break;
                }
            }
            if(pn){
                aoki = true;
                tkhs = false;
            }
        }
        if(tkhs){
            aoki = false;
            break;
        }
    }

    if(aoki==tkhs) cout << "error" << endl;
    if(aoki) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;

    return 0;
}