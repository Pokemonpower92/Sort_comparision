#include "sorting.hpp"
#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
  vector<int> vec;
  int num;
  string line;

  while(getline(cin, line)){
    istringstream ss;
    ss.str(line);
    vec.clear();

    while(ss >> num) vec.push_back(num);

    printf("Before sort: ");
    for(size_t i = 0; i != vec.size(); i++){
      printf("%d ", vec[i]);
    }
    printf("\n");

    q_sort(vec);

    printf("After sort: ");
    for(size_t i = 0; i != vec.size(); i++){
      printf("%d ", vec[i]);
    }
    printf("\n");
  }
  return 0;
}
