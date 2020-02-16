#include <iostream>  
#include <chrono>  
using namespace std;  
using namespace chrono; // std 내에 chrono 가 존재  
int main(void) {  
  system_clock::time_point start = system_clock::now();  
  long long a = 0;  
  for (int i = 0; i < 10000; i++) {
	  for (int j = 0; j < 10000; j++) {  
	      a++;  
	  }  
  }
  system_clock::time_point end = system_clock::now();  
  microseconds microSec = duration_cast<microseconds>(end - start);  
  cout << microSec.count()/1000 << "ms\n";  
  return 0;  
} 
