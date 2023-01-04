#ifndef AMMONIUM_HYDROSULFIDE_HPP
#define AMMONIUM_HYDROSULFIDE_HPP

#include "molecule.hpp"

inline double svpNH4SHLewis(double T)
{
  return pow(10., 14.82 - 4705. / T) * 101325. * 101325.;
}

template<int N> 
class AmmoniumHydrosulfide {
  static_assert(N == 2, "undefined phase for AmmoniumHydrosulfide");
};

// ice
template<>
class AmmoniumHydrosulfide<2> : public Molecule {
public:
  AmmoniumHydrosulfide(): Molecule("NH4SH(s)", 51.111, 0., 0., 93.12E3)
  {
    phase_id_ = 2;
    shomate_func_ptr_ = get_shomate;
    svp_func_ptr_ = svpNH4SHLewis;
  }

	static void get_shomate(Real const *&shomate, Real T) {
    shomate = shomate1_;
  }

private:
	static Real const shomate1_[7];
};

#endif
