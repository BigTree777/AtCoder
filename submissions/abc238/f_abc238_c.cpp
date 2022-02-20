#include<bits/stdc++.h>
#define DIV 998244353
#define INV 499122177 // 逆元を利用する
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ull N;
    cin >> N;

    // get number of digit
    int nod = 0;
    ull a = N / 10;
    while(a >= 1){
        nod += 1;
        a /= 10;
    }

    ull ans = 0;
    ull nines = 0;
    ull num;
    ull ans1, ans2, _ans;
    for(int i=0; i<nod; i++){
        num = powl(10, i) * 9;
        ans1 = (ull)(num + 1) % DIV;
        ans2 = (ull)(num) % DIV;
        _ans = (ull)(ans1 * ans2) % DIV;
        _ans = _ans * INV;
        _ans = _ans % DIV;
        ans += _ans;
        // _ans = (ull)(ans1 * ans2 * 0.5) % DIV; //小数を使わない, 精度が保証されていない
        // cout << num << ": " << _ans << endl;
        
        nines += 9 * powl(10, i);
    }
    ull surplus = N - nines;
    ans1 = (ull)(1 + surplus)  % DIV;
    ans2 = (ull)(surplus) % DIV;
    _ans = (ull)(ans1 * ans2) % DIV;
    _ans = _ans * INV;
    _ans = _ans % DIV;
    ans += _ans;
    // ans += (ull)(ans1 * ans2 * 0.5) % DIV;

    ull f_ans = ans % DIV;
    cout << f_ans << endl;

    return 0;
}
// #include<bits/stdc++.h>
// #define DIV 998244353
// using namespace std;
// using ll = long long;
// using ull = unsigned long long;

// int main(){
//     ull N;
//     cin >> N;

//     // get number of digit
//     int nod = 0;
//     ull a = N / 10;
//     while(a >= 1){
//         nod += 1;
//         a /= 10;
//     }

//     ull ans = 0;
//     ull nines = 0;
//     ull num;
//     for(int i=0; i<nod; i++){
//         num = 9 * powl(10, i);
//         ans += (num / DIV) * 9 * powl(10, i) * 0.5 + (num / DIV) * 0.5;
//         if(ans > (ull)DIV){
//             ans = ans % (ull)DIV;
//         }
//         nines += 9 * powl(10, i);
//     }
//     ull surplus = N - nines;
//     ull n_surplus = surplus % DIV;
//     ans += (surplus + 1) * n_surplus * 0.5;

//     ull f_ans = ans % DIV;
//     cout << f_ans << endl;

//     return 0;
// }