#include <iostream>
#include <iomanip>

int main(void){
  int N;
  std::cin >> N;
  if(N>41)
    N += 1;
  std::cout << "AGC" << std::setw(3) << std::setfill('0') << N << std::endl;
  return 0;
}
