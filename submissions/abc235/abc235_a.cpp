#include<stdio.h>
#include<iostream>
#include<string>

int main(void){
  std::string input;
  std::cin >> input;
  std::string str_a, str_b, str_c;
  str_a = input[0];
  str_b = input[1];
  str_c = input[2];
  int a, b, c;
  a = std::stoi(str_a);
  b = std::stoi(str_b);
  c = std::stoi(str_c);
  int abc, bca, cab, ans;
  abc = 100*a + 10*b + c;
  bca = 100*b + 10*c + a;
  cab = 100*c + 10*a + b;
  ans = abc + bca + cab;
  std::cout << ans << std::endl; 
  return 0;
}
