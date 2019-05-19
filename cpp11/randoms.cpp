/*
 * This code tries to move away from rand() which have max value of 32,767
 * So, not uniform when you want to generate in range 0, 99
 *
 * srand() seeds with time(NULL)
 *  - First: NULL is not used in CPP
 *  - Second: many people who calls it as same time, gets same random numbers
 *  - Third: time increase frequency is 1Hz, increasing pretty fast,
 *          generating same random numbers multiple times.
 *
 * Video:
 * https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful
 */

#include <iostream>
#include <random>

int main() {
  /*
   * mt -> generates random number between [0, 2^32)
   * 1729 -> some random deterministic 32-bit seed
   * random_device -> for random non-deterministic seed, slow than deterministic
   * but cryptographically secure and non-reproducible
   */
  std::random_device rd;
  // std::mt19937 mt( 1729 );
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0, 99); // Inclusive 0, 99

  for (int i = 0; i < 16; i++) {
    std::cout << dist(mt) << " ";
  }
  std::cout << '\n';
  return 0;
}
