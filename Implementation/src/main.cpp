#include <iostream>
#include "../include/dfa.h"
#include "../include/examples.h"

int main(int argc, char *argv[]) {
  DFA M = EX::hw05();

  int T1[] = {0,0,0,1,1,1};
  std::vector<int> trace1 (T1, T1 + sizeof(T1) / sizeof(int) );

  std::vector<bool>  path = M.execute_trace(trace1);
  for (const auto i: path)
    std::cout << i << ' ';
  std::cout<<std::endl;

}
