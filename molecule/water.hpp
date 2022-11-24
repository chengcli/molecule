#ifndef WATER_HPP
#define WATER_HPP

#include "molecule.hpp"

namespace WaterVaporPressures {
  Real svpUMich(Real T);
  Real svpAntoine(Real T);
  Real svpHubner(Real T);
  Real svpFray(Real T);
  Real svpBriggsS(Real T);
  Real svpBolton(Real T);
  Real svpSmithsonian(Real T);
  Real svpIdeal(Real T);
};

template<int N> 
class Water {
  static_assert((N >= 0) && (N <= 2), "undefined phase for Water");
};

// vapor
template<>
class Water<0> : public Molecule {
public:
  Water(): Molecule("H2O", 18.0153, 273.16, 611.657)
  {
    shomate_func_ptr_ = get_shomate;
    svp_func_ptr_ = WaterVaporPressures::svpBriggsS;
  }

	static void get_shomate(Real const *&shomate, Real T) {
    //T = std::min(std::max(500., T), 6000.);
    if (T < 1700.) {
      shomate = shomate1_;
    } else
      shomate = shomate2_;
  }

private:
	static Real const shomate1_[7];	// 500 ~ 1700 K
	static Real const shomate2_[7];	// 1700 ~ 6000 K
};

// liquid
template<>
class Water<1> : public Molecule {
public:
  Water(): Molecule("H2O(l)", 18.0153, 273.16, 611.657)
  {
    phase_id_ = 1;
    enthalpy_offset_ = -45.0144E3;
    shomate_func_ptr_ = get_shomate;
    svp_func_ptr_ = WaterVaporPressures::svpBriggsS;
  }

	static void get_shomate(Real const *&shomate, Real T) {
    shomate = shomate1_;
  }

private:
	static Real const shomate1_[7];
};

// ice
template<>
class Water<2> : public Molecule {
public:
  Water(): Molecule("H2O(s)", 18.0153, 273.16, 611.657)
  {
    phase_id_ = 2;
    enthalpy_offset_ = -51.0138E3;
    shomate_func_ptr_ = get_shomate;
    svp_func_ptr_ = WaterVaporPressures::svpBriggsS;
  }

	static void get_shomate(Real const *&shomate, Real T) {
    shomate = shomate1_;
  }

private:
	static Real const shomate1_[7];
};

#include "water_vapors.hpp"

#endif
