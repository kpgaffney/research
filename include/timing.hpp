#ifndef RESEARCH_TIMING_HPP
#define RESEARCH_TIMING_HPP

#include <chrono>

namespace timing {

/**
 * Measure the time taken to execute a function.
 * @param f The function
 * @return The time in seconds.
 */
template <typename F> double time(F &&f) {
  auto t0 = std::chrono::high_resolution_clock::now();
  f();
  auto t1 = std::chrono::high_resolution_clock::now();
  return std::chrono::duration<double>(t1 - t0).count();
}

} // namespace timing

#endif // RESEARCH_TIMING_HPP
