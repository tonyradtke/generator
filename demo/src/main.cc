#include "Generator.hh"
#include "Stats.hh"

#include <vector>
#include <string>
#include <iostream>

int main() {


std::vector<std::string> sampleSpace {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

double sampleMean {5};
double sampleSD {1};
Generator g(sampleMean, sampleSD, sampleSpace);

for (int i = 0; i < 10; ++i) {
  std::cout << g.sample() << "\n";
}


}
