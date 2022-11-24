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
    phase_id_ = 0;
    set_shomate_ptr_(shomate1_);
  }

private:
	static Real const shomate1_[7];	// dummy
};

// dummy shomate
Real const DummySpecies<0>::shomate1_[7] = {1., 0., 0., 0., 0., 0., 0.};

#endif
