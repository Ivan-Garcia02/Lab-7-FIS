#include <iostream>
#include <stdlib.h>
#include <unistd.h>

int main() {
  while (true) {
    std::cout << "\033[7mbold red text\033[0m\n";
    sleep(1);
    system("clear");
    std::cout << "\033[0mbold red text\033[0m\n";
    sleep(1);
    system("clear");
  }
  
  
}