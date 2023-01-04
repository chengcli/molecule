/** @file molecule.hpp
 * @brief
 *
 * @author Cheng Li (chengcli@umich.edu)
 * @date Saturday Jul 10, 2021 14:50:00 PDT
 * @bug No known bugs.
 */

#ifndef MOLECULE_HPP
#define MOLECULE_HPP

// C/C++ header
#include <cmath>
#include <string>
#include <iosfwd>

// molecules
#include <configure.hpp>

class GasMixture;

using ShomateFunc = void (*)(Real const*&, Real);
using VaporPressureFunc = Real (*)(Real);

inline void null_shomate(Real const *&, Real) {}

class Molecule {
  friend std::ostream& operator<<(std::ostream &os, Molecule const& my);
public:
// public access members
  std::string     formula;
  std::string     id;
  Real            mu;

  Real            tripleT;
  Real            tripleP;
  Real            latentH;

// functions
  Molecule(): // for use of mixture
    formula(""), mu(0.), tripleT(0.), tripleP(0.), latentH(0.),
    phase_id_(0),
    enthalpy_ref_(0.),
    entropy_ref_(0.)
  {}

  Molecule(std::string formula_, Real mu_, Real t3, Real p3, Real l3):
    formula(formula_), mu(mu_/1.E3), tripleT(t3), tripleP(p3), latentH(l3),
    shomate_func_ptr_(null_shomate),
    phase_id_(0),
    enthalpy_ref_(0.),
    entropy_ref_(0.)
  {}

  Real cp(Real T) const {
    return cp_shomate_(T);
  }

  Real entropy(Real T) const {
    return entropy_shomate_(T) - entropy_ref_;
  }

  Real enthalpy(Real T) const {
    return enthalpy_shomate_(T) - enthalpy_ref_;
  }

  Real svp(Real T) const {
    return svp_func_ptr_(T);
  }

  void setReferenceTemperature(Real T) {
    enthalpy_ref_ = enthalpy(T);
    entropy_ref_ = entropy(T);
  }

protected:
  ShomateFunc       shomate_func_ptr_;
  VaporPressureFunc svp_func_ptr_;
  int               phase_id_;

  /*void set_shomate_ptr_(Real const *shomate) {
    shomate_ = shomate;
  }*/

  Real cp_shomate_(Real T) const {
    Real const *shomate_;
    shomate_func_ptr_(shomate_, T);
    Real result;
    T /= 1.E3;
    result = shomate_[0] + shomate_[1]*T + shomate_[2]*T*T 
      + shomate_[3]*T*T*T + shomate_[4]/(T*T);
    return result;
  }

  Real entropy_shomate_(Real T) const {
    Real const *shomate_;
    shomate_func_ptr_(shomate_, T);
    Real result;
    T /= 1.E3;
    result = shomate_[0]*log(T) + shomate_[1]*T + 0.5*shomate_[2]*T*T
      + 1./3.*shomate_[3]*T*T*T - shomate_[4]/(2.*T*T) + shomate_[6];
    return result;
  }

  Real enthalpy_shomate_(Real T) const {
    Real const *shomate_;
    shomate_func_ptr_(shomate_, T);
    Real result;
    T /= 1.E3;
    result = shomate_[0]*T + 0.5*shomate_[1]*T*T + 1./3.*shomate_[2]*T*T*T
      + 1./4.*shomate_[3]*T*T*T*T - shomate_[4]/T + shomate_[5];
    return result*1.E3;
  }

private:
  // reference value
  Real            enthalpy_ref_;
  Real            entropy_ref_;
};

#endif
