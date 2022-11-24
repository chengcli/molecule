#ifndef METHANE_HPP
#define METHANE_HPP

#include "molecule.hpp"

template<int N>
class Methane {
  static_assert((N >= 0) || (N <= 2), "undefined phase for Methane");
};

// vapor
template<>
class Methane<0> : public Molecule {
public:
  Methane(): Molecule("CH4", 16., 90.69, 11696.)
  {
    shomate_func_ptr_ = get_shomate;
  }

	static void get_shomate(Real const *&shomate, Real T) {
    //T = std::min(std::max(298., T), 6000.);
    if (T < 1300.) {
      shomate = shomate1_;
    } else
      shomate = shomate2_;
  }

private:
	static Real const shomate1_[7];	
	static Real const shomate2_[7];	
};

// liquid
template<>
class Methane<1> : public Molecule {
public:
  Methane(): Molecule("CH4(l)", 16., 90.69, 11696.)
  {
    phase_id_ = 1;
    enthalpy_offset_ = -8.6E3;
    shomate_func_ptr_ = get_shomate;
  }

	static void get_shomate(Real const *&shomate, Real T) {
    shomate = shomate1_;
  }

private:
	static Real const shomate1_[7];
};

// ice
template<>
class Methane<2> : public Molecule {
public:
  Methane(): Molecule("CH4(s)", 16., 90.69, 11696.)
  {
    phase_id_ = 2;
    enthalpy_offset_ = -9.7E3;
    shomate_func_ptr_ = get_shomate;
  }

	static void get_shomate(Real const *&shomate, Real T) {
    shomate = shomate1_;
  }

private:
	static Real const shomate1_[7];
};

#endif
