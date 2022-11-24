#ifndef GAS_MIXTURE_HPP
#define GAS_MIXTURE_HPP

// C/C++
#include <iosfwd>

// molecules headers
#include <configure.hpp>
#include "molecule.hpp"

class GasMixture {
  friend std::ostream& operator<<(std::ostream &os, GasMixture const& my);
public:
// public access members
  std::string   formula;
  Real          mu;

// functions
  GasMixture() {}
  GasMixture(std::string mixture_string);

  operator Molecule() const {
    Molecule a = Molecule();
    a.formula = formula;
    a.mu = mu;
    return a;
  }

  Real cp(Real T) {
    Real result = 0.;
    for (size_t i = 0; i < comp_.size(); ++i) {
      result += mixr_[i]*comp_[i].cp(T);
    }
    return result;
  }

  Real entropy(Real T) {
    Real result = 0.;
    for (size_t i = 0; i < comp_.size(); ++i) {
      result += mixr_[i]*comp_[i].entropy(T);
    }
    return result;
  }

  Real enthalpy(Real T) {
    Real result = 0.;
    for (size_t i = 0; i < comp_.size(); ++i) {
      result += mixr_[i]*comp_[i].enthalpy(T);
    }
    return result;
  }

  void setReferenceTemperature(Real T) {
    for (size_t i = 0; i < comp_.size(); ++i) {
      comp_[i].setReferenceTemperature(T);
    }
  }

protected:
  std::vector<Molecule> comp_;
  std::vector<Real>     mixr_;
};

#endif
