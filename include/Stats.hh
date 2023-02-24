#ifndef STATS_H
#define STATS_H

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

class Distribution {
public:
  std::default_random_engine m_generator;
  std::normal_distribution<double> m_distribution;
  double m_lower; 
  double m_upper; 
  double m_mean;

  Distribution();  
  Distribution(double f_mean, double f_sd);  
  Distribution(const Distribution& f_d);
  double sample();   
  void set_bounds(double f_low, double f_hi); 
  friend std::ostream& operator<<(std::ostream& out, Distribution& f_d); 
};

#endif
