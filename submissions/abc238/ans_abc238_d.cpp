// source: https://atcoder.jp/contests/abc238/editorial/3359

// 1. x AND y = a よりaはxとyの両方で1となっている位の総和
// 2. xとyの両方で1となっている位の集合をA,その総和をAs，片方で1となっている位の集合をB，その総和をBsとする
// 3. この時，sはA,Bを用いて s = 2As + Bsとできる
// 4. また，aは明らかにAsと等しいから， s = 2a + Bs -> Bs = s - 2a
// 5. 次にBに注目すると，BとBs, AとAsは一対一の関係であり，BとAは互いに素であるから，As AND Bs = 0
// (Asを二進数表記した際に1となるような位の集合はAと一致し，BsとBに関しても同様のことがいえる)
// 6. したがって問題文の条件を満たすとき，s-2a >= 0 かつ s-2a AND a = 0
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ll T;
    cin >> T;
	while(T--){
		ll a,s; cin >> a >> s;
		string ans = "No";
		if(2*a <= s){
			ll differ = s-2*a;
			if((differ & a) == 0) ans = "Yes";
		}
		cout << ans << endl;
	}
}
