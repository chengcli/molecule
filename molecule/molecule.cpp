// C/C++
#include <iostream>

// molecules
#include "molecule.hpp"

std::ostream& operator<<(std::ostream &os, Molecule const& my)
{
  os << "Formula = " << my.formula << std::endl;
  os << "mu = " << my.mu*1.E3 << " g/mol" << std::endl;
  os << "tripleT = " << my.tripleT << " K" << std::endl;
  os << "tripleP = " << my.tripleP << " pa" << std::endl;
  os << "phase_id = " << my.phase_id_ << std::endl;
  os << "enthalpy_offset = " << my.enthalpy_offset_/1.E3 << " kJ/mol" << std::endl;
  os << "enthalpy_ref = " << my.enthalpy_ref_/1.E3 << " kJ/mol" << std::endl;
  os << "entropy_ref = " << my.entropy_ref_ << " J/(mol.K)" << std::endl;
  os << "cp (300 K) = " << my.cp(300.) << " J/(mol.K)" << std::endl;
  return os;
}
