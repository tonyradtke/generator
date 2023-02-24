#include "Generator.hh"
#include "Stats.hh"

#include <vector>
#include <string>
#include <iostream>

int main() {


std::vector<std::string> sample {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

Generator g(5, 1, sample);

for (int i = 0; i < 10; ++i) {
  std::cout << g.sample() << "\n";
  
}


}
