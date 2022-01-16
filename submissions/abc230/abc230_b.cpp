#include<iostream>
#include<iomanip>
#include<string>

int main(){
  std::string T = "oxx";
  for(int n = 0; n < 100000; n++){
    T += "oxx";
  }
  std::string S, t;
  bool ok = false;
  std::cin >> S;
  int s_size = S.size();
  for(int i = 0; i < 3; i++){
    t = T.substr(i, s_size);
    if(S == t){
      ok = true;
      break;
    }
  }
  if(ok)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;
  return 0;
}
