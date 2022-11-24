#ifndef HYDROGEN_HPP
#define HYDROGEN_HPP

#include "molecule.hpp"

template<int N> 
class Hydrogen {
  static_assert(N == 0, "undefined phase for Hydrogen");
};

// vapor
template<>
class Hydrogen<0> : public Molecule {
public:
	Hydrogen();

  Real fpara_equil(Real T);
  Real cp_para(Real T);
  Real cp_ortho(Real T);
  Real cp_norm(Real T);
  Real cp_equil(Real T);

	static void get_shomate(Real const *&shomate, Real T) {
    //T = std::min(std::max(298., T), 6000.);
    if (T < 1000.)
      shomate = shomate1_;
    else if (T >= 1000. && T < 2500.)
      shomate = shomate2_;
    else
      shomate = shomate3_;
  }

private:
  Real FJ_[20];
  Real DJ_[20];

	static Real const shomate1_[7];	// 298 ~ 1000 K
	static Real const shomate2_[7];	// 1000 ~ 2500 K
	static Real const shomate3_[7];	// 2500 ~ 6000 K

  void get_cp_(Real *cp_para, Real *cp_equil, Real *cp_norm, Real *cp_ortho, Real T);
};

#endif
