#ifndef HELIUM_HPP
#define HELIUM_HPP

#include "molecule.hpp"

template<int N> 
class Helium {
  static_assert(N == 0, "undefined phase for Helium");
};

template<>
class Helium<0> : public Molecule {
public:
  Helium(): Molecule("He", 4.0026, 1.772, 30.016E3, 0.)
  {
    shomate_func_ptr_ = get_shomate;
  }

  static void get_shomate(Real const *&shomate, Real T) {
    shomate = shomate1_;
  }

protected:
  static Real const shomate1_[7]; // 300 ~ 600 K
};

#endif
