#ifndef RESEARCH_TIMING_HPP
#define RESEARCH_TIMING_HPP

#include <chrono>
#include <vector>

namespace timing {

struct Result {
  std::vector<double> times;
  double mean;
};

/**
 * Measure the time taken to execute a function.
 * @param f Function.
 * @param n Number of trials.
 * @return A Result containing timing information.
 */
template <typename F> Result time(F &&f, size_t n = 1) {
  std::vector<double> times(n);
  double mean = 0.0;

  for (size_t i = 0; i < n; ++i) {
    auto t0 = std::chrono::high_resolution_clock::now();
    f();
    auto t1 = std::chrono::high_resolution_clock::now();
    double t = std::chrono::duration<double>(t1 - t0).count();

    times[i] = t;
    mean += t / n;
  }

  return Result{times, mean};
}

} // namespace timing

#endif // RESEARCH_TIMING_HPP
