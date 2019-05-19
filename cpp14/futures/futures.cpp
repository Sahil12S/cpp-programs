#include <algorithm>
#include <future>
#include <iostream>
#include <random>
#include <set>

std::set<int> make_sorted_random(const size_t num_elems) {
  std::set<int> retval;
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<> dis(0, num_elems - 1);

  std::generate_n(std::inserter(retval, retval.end()), num_elems,
                  [&]() { return dis(gen); });

  return retval;
}

int main() {
  // auto f1 = std::async( make_sorted_random, 1000000 );
  // auto f2 = std::async( make_sorted_random, 1000000 );
  auto f1 = std::async(std::launch::async, make_sorted_random, 1000000);
  auto f2 = std::async(std::launch::async, make_sorted_random, 1000000);

  // std::cout << make_sorted_random( 1000000 ).size()  << " " <<
  // make_sorted_random( 1000000 ).size() << '\n';
  std::cout << f1.get().size() << " " << f2.get().size() << '\n';
  return 0;
}

/*
 *      INSTRUCTIONS ON COMPILING
 *
 * 1. When doing normally:
 *      g++ ./futures.cpp -std=c++14
 *
 *  Optimize it using -O3
 *      g++ ./futures.cpp -std=c++14 -O3
 *
 * 2. Using Futures
 *      g++ ./futures.cpp -std=c++14 -O3 -pthread
 *
 *
 * Run as:
 *      /use/bin/time ./a.out
 */