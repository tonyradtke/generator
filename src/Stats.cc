#include <string>
#include <stdexcept>
#include <tuple>
#include <float.h>
#include <sstream>
#include <fstream> 
#include <iostream>
#include <set>
#include <stdlib.h>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <random>

#include "Stats.hh"

Distribution::Distribution() {
  set_bounds(0,99999);
  m_distribution = std::normal_distribution<double>(0, 0);
  m_mean = 0;
}

Distribution::Distribution(double f_mean, double f_sd) {
  set_bounds(0,99999);
  m_distribution = std::normal_distribution<double>(f_mean, f_sd);
  m_mean = f_mean;
}

Distribution::Distribution(const Distribution& f_d) {
  m_generator = f_d.m_generator;
  m_distribution = f_d.m_distribution; 
  m_lower = f_d.m_lower;
  m_upper = f_d.m_upper;
}

double Distribution::sample() {
  double gen = m_distribution(m_generator);
  while (gen < m_lower or gen > m_upper) { //curr invalid, retry
    gen = m_distribution(m_generator);
  }   
  return gen;
}

void Distribution::set_bounds(double f_low, double f_hi) {
  m_lower = f_low;
  m_upper= f_hi;
}

std::ostream& operator<<(std::ostream& out, Distribution& f_d) { return out << f_d.m_mean; }
