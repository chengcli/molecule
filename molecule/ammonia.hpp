#ifndef AMMONIA_HPP
#define AMMONIA_HPP

#include "molecule.hpp"

namespace AmmoniaVaporPressures {
  Real svpUMich(Real T);
  Real svpAntoine(Real T);
  Real svpHubner(Real T);
  Real svpFray(Real T);
  Real svpBriggsS(Real T);
  Real svpIdeal(Real T);
};

template<int N> 
class Ammonia {
  static_assert((N >= 0) && (N <= 2), "undefined phase for Ammonia");
};

// vapor
template<>
class Ammonia<0> : public Molecule {
public:
  Ammonia(): Molecule("NH3", 17.0306, 195.4, 6060., 0.)
  {
    shomate_func_ptr_ = get_shomate;
    svp_func_ptr_ = AmmoniaVaporPressures::svpBriggsS;
  }

  static void get_shomate(Real const *&shomate, Real T) {
    //T = std::min(std::max(298., T), 6000.);
    if (T < 1300.) {
      shomate = shomate1_;
    } else
      shomate = shomate2_;
  }

private:
  static Real const shomate1_[7]; // 298 ~ 1300 K
  static Real const shomate2_[7]; // 1300 ~ 6000 K
};

// liquid
template<>
class Ammonia<1> : public Molecule {
public:
  Ammonia(): Molecule("NH3(l)", 17.0306, 195.4, 6060., 23.5E3)
  {
    phase_id_ = 1;
    shomate_func_ptr_ = get_shomate;
    svp_func_ptr_ = AmmoniaVaporPressures::svpBriggsS;
  }

  static void get_shomate(Real const *&shomate, Real T) {
    shomate = shomate1_;
  }

private:
  static Real const shomate1_[7];
};

// ice
template<>
class Ammonia<2> : public Molecule {
public:
  Ammonia(): Molecule("NH3(s)", 17.0306, 195.4, 6060., 31.2E3)
  {
    phase_id_ = 2;
    shomate_func_ptr_ = get_shomate;
    svp_func_ptr_ = AmmoniaVaporPressures::svpBriggsS;
  }

  static void get_shomate(Real const *&shomate, Real T) {
    shomate = shomate1_;
  }

private:
  static Real const shomate1_[7];
};

#include "ammonia_vapors.hpp"

#endif
