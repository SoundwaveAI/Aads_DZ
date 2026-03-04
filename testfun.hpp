#ifndef TESTFUN_HPP
#define TESTFUN_HPP
#include <iostream>

template< class T >
struct SumM {
  size_t total = 0;
  void operator()(const T& val) {
    total += val;
  }
};

template< class T >
struct PrintM {
  void operator()(const T& val) {
    std::cout << val << " ";
  }
};

#endif
