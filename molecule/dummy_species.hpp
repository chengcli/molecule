#ifndef DUMMY_SPECIES_HPP
#define DUMMY_SPECIES_HPP

#include "molecule.hpp"

template<int N> 
class DummySpecies {
  static_assert(N == 0, "undefined phase for DummySpecies");
};

// vapor
template<>
class DummySpecies<0> : public Molecule {
public:
  DummySpecies() : Molecule("Dummy", 1., 0., 0.)
  {
    shomate_func_ptr_ = get_shomate;
  }

	static void get_shomate(Real const *&shomate, Real T) {
    shomate = shomate1_;
  }

private:
	static Real const shomate1_[7];	// dummy
};

#endif
