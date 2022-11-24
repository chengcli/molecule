// C/C++
#include <stdexcept>
#include <iostream>

// debugger
#include <debugger.hpp>

// molecules
#include "molecules.hpp"
#include "gas_mixture.hpp"
#include "vectorize.hpp"

std::ostream& operator<<(std::ostream &os, GasMixture const& my)
{
  os << "Formula = " << my.formula << std::endl;
  os << "mu = " << my.mu*1.E3 << " g/mol" << std::endl;
  for (int i = 0; i < my.comp_.size(); ++i)
    os << my.comp_[i].formula << " = " << my.mixr_[i] << std::endl;
  return os;
}

GasMixture::GasMixture(std::string mixture_string):
  formula(mixture_string), mu(0.)
{
  auto mixture = Vectorize<std::string>(mixture_string.c_str(), ";");

  comp_.resize(mixture.size());
  mixr_.resize(mixture.size());

  Real sum = 0;
  for (int i = 0; i < mixture.size(); ++i) {
    auto component = Vectorize<std::string>(mixture[i].c_str(), ":");
    std::string name = component[0];

    try {
      mixr_[i] = std::stof(component[1]);
      sum += mixr_[i];
    } catch (...) {
      Debugger::Fatal("GasMixture", "cannot parse mixture string");
    }

    if (name == "H2") {
      comp_[i] = Hydrogen<0>();
    } else if (name == "He") {
      comp_[i] = Helium<0>();
    } else if (name == "CH4") {
      comp_[i] = Methane<0>();
    } else if (name == "H2O") {
      comp_[i] = Water<0>();
    } else if (name == "NH3") {
      comp_[i] = Ammonia<0>();
    } else if (name == "H2S") {
      comp_[i] = HydrogenSulfide<0>();
    } else if (name == "Dummy") {
      comp_[i] = DummySpecies<0>();
    } else {
      Debugger::Fatal("GasMixture", "unrecognized molecule name", name);
    }
  }

  // normalize mixing ratio
  for (int i = 0; i < mixture.size(); ++i)
    mixr_[i] /= sum;

  // mean molecular weight
  for (int i = 0; i < mixture.size(); ++i)
    mu += mixr_[i]*comp_[i].mu;
}
