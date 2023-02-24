#ifndef GENERATOR_H
#define GENERATOR_H

#include "Stats.hh"

template <typename T>
class Generator { 
public: 

   Distribution m_dis;
  std::map<int , T> m_sampleSpaceMap;

  Generator(){}
  
  Generator(double f_distMean, double f_distSD, std::vector<T> f_sampleSpace) {
    auto asMap = map_from_vector(f_sampleSpace);
    m_dis = Distribution(f_distMean, f_distSD); //might need a default ctor for the Distribution class 
    m_sampleSpaceMap = (asMap); 
    set_bounds(0, m_sampleSpaceMap.size());
  }

  Generator(double f_distMean, double f_distSD, std::map<int, T> f_sampleSpaceMap) {
    m_dis = Distribution(f_distMean, f_distSD); //might need a default ctor for the Distribution class 
    m_sampleSpaceMap = (f_sampleSpaceMap); 
    set_bounds(0, m_sampleSpaceMap.size());
  }

  T sample() {
    return m_sampleSpaceMap[int(m_dis.sample())]; 
  }
  
  void set_bounds(double f_l, double f_h) {
    m_dis.set_bounds(f_l, f_h);
  }
  
  std::map<int, T> map_from_vector(std::vector<T> f_v) {
    std::map<int, T> res;
    for (int i = 0; i < f_v.size(); ++i) {
      res[i] = f_v[i];
    }
    return res;
  }

  void show(std::vector<T> f_v, std::map<T, int> f_counts) {

    std::map<int, std::string> sorted;
    for (auto e : f_counts) { sorted[e.second] = e.first; }
    for (const auto& e : f_v) { std::cout << std::setw(5) << f_counts[e] << "   ";  }
    std::cout << "\n";
    for (const auto& e : f_v) {  std::cout << std::setw(5) << e<< "   "; }
    std::cout << "\n";

  }
  
  std::map<T, int> get_counts(int f_iters) {
    std::map<T, int> counts;
    for (uint32_t i = 0; i < f_iters; ++i) { 
      counts[sample()]++;
    }
    return counts;
  }


};


#endif
