#ifndef HYDROGEN_SULFIDE_HPP
#define HYDROGEN_SULFIDE_HPP

#include "molecule.hpp"

namespace HydrogenSulfideVaporPressures {
  Real svpAntoine(Real T);
};

template<int N> 
class HydrogenSulfide {
  static_assert((N >= 0) && (N <= 2), "undefined phase for DummySpecies");
};

// vapor
template<>
class HydrogenSulfide<0> : public Molecule {
public:
  HydrogenSulfide() : Molecule("H2S", 34.081, 187.66, 2.32E4)
  {
    shomate_func_ptr_ = get_shomate;
    svp_func_ptr_ = HydrogenSulfideVaporPressures::svpAntoine;
  }

	static void get_shomate(Real const *&shomate, Real T) {
    //T = std::min(std::max(298., T), 6000.);
    if (T < 1400.) {
      shomate = shomate1_;
    } else
      shomate = shomate2_;
  }

private:
	static Real const shomate1_[7];	// 298 ~ 1400 K
	static Real const shomate2_[7];	// 1400 ~ 6000 K
};

// liquid
template<>
class HydrogenSulfide<1> : public Molecule {
public:
  HydrogenSulfide() : Molecule("H2S(l)", 34.081, 187.66, 2.32E4)
  {
    phase_id_ = 1;
    enthalpy_offset_ = -19.5E3;
    shomate_func_ptr_ = get_shomate;
    svp_func_ptr_ = HydrogenSulfideVaporPressures::svpAntoine;
  }

	static void get_shomate(Real const *&shomate, Real T) {
    shomate = shomate1_;
  }
private:
	static Real const shomate1_[7];
};

// ice
template<>
class HydrogenSulfide<2> : public Molecule {
public:
  HydrogenSulfide() : Molecule("H2S(s)", 34.081, 187.66, 2.32E4)
  {
    phase_id_ = 2;
    enthalpy_offset_ = -25.4E3;
    shomate_func_ptr_ = get_shomate;
    svp_func_ptr_ = HydrogenSulfideVaporPressures::svpAntoine;
  }

	static void get_shomate(Real const *&shomate, Real T) {
    shomate = shomate1_;
  }

private:
	static Real const shomate1_[7];
};

#include "hydrogen_sulfide_vapors.hpp"

#endif
