#if !defined(WORLD_HPP)
#define WORLD_HPP

#include "daisy.hpp"

#include <random>
#include <vector>

class World {
 private:
  int size_;
  int max_age_;
  std::vector<Daisy> daisies_;
  std::default_random_engine gen_;

 public:
  World(int, double, double, int);
  void compute_temperatures(double solar_luminosity);
  double global_temperature() const;
  void step(double solar_luminosity);
  void compute_diffusion();
  void spread();

  void World::print() {
    for (int i{0}; i < size_; ++i) {
      for (int j{0}; j < size_; ++j) {
        std::cout << daisies_[i * size_ + j];
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }
};

#endif  // WORLD_HPP
