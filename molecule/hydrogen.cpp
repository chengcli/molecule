/** @file hydrogen.cpp
 * @brief
 *
 * @author Cheng Li (chengcli@umich.edu)
 * @date Saturday Jul 10, 2021 14:55:03 PDT
 * @bug No known bugs.
 */

#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <cmath>

// molecules headers
#include <configure.hpp>
#include "hydrogen.hpp"
#include "constants.hpp"

#define SQUARE(V) (V * V)
#define JMAX 20

static Real const FACT_cgs = Constants::hPlanck_cgs*Constants::cLight_cgs/Constants::kBoltz_cgs;

Hydrogen<0>::Hydrogen() :
  Molecule("H2", 2., 13.8033, 7.04E3, 0.)
{
  Real B0 = 59.322,
       D0 = 4.71e-02;
   
  for (int J = 0; J < JMAX; J++) {
    DJ_[J] = ((J/2)*2 == J) ? 2*J+1 : 3*(2*J+1);
    FJ_[J] = B0 * J * (J + 1.) - D0 * SQUARE(J*(J + 1.));
  }

  shomate_func_ptr_ = get_shomate;
}

Real Hydrogen<0>::fpara_equil(Real T) {
  // compute partition functions
  Real Zpara = 0, Zortho = 0;

  for (size_t J = 0; J < JMAX; J += 2)
      Zpara += DJ_[J] * exp(-FJ_[J]*FACT_cgs/T);

  for (size_t J = 1; J < JMAX; J += 2)
      Zortho += DJ_[J] * exp(-FJ_[J]*FACT_cgs/T);

  return Zpara/(Zpara + Zortho);
}

void Hydrogen<0>::get_cp_(Real *cp_para, Real *cp_equil, Real *cp_norm, Real *cp_ortho, Real T)
{
    Real FORTH = 0.75;
    Real FPARA = 0.25;
   
    Real ZEQ = 0.0;
    Real SEQ1 = 0.0;
    Real SEQ2 = 0.0;
   
    Real ZORTHO = 0.0;
    Real SO1 = 0.0;
    Real SO2 = 0.0;
   
    Real ZPARA = 0.0;
    Real SP1 = 0.0;
    Real SP2 = 0.0;
   
    for (int JQ=9; JQ>=0; JQ--) {
        Real X = ( FACT_cgs / T ) * FJ_[JQ];
        Real P = DJ_[JQ] * exp( -X );
      
        ZEQ += P;
        SEQ1 += DJ_[JQ] * SQUARE(X) * exp(-X);
        SEQ2 += DJ_[JQ] * X * exp(-X);
      
        if ( (JQ/2)*2 == JQ ) {
            ZPARA += P;
            SP1 += DJ_[JQ] * SQUARE(X) * exp(-X);
            SP2 += DJ_[JQ] * X * exp(-X);
        } else {
            ZORTHO += P;
            SO1 += DJ_[JQ] * SQUARE(X) * exp(-X);
            SO2 += DJ_[JQ] * X * exp(-X);
        }
    }
   
    *cp_equil = 5.0/2.0 + SEQ1/ZEQ - SQUARE(SEQ2/ZEQ);
    *cp_equil = (*cp_equil)*Constants::Rgas;

    *cp_ortho = 5.0/2.0 + SO1/ZORTHO - SQUARE(SO2/ZORTHO);
    *cp_ortho = (*cp_ortho)*Constants::Rgas;

    *cp_para = 5.0/2.0 + SP1/ZPARA - SQUARE(SP2/ZPARA);
    *cp_para = (*cp_para)*Constants::Rgas;

    *cp_norm = FORTH*(*cp_ortho) + FPARA*(*cp_para);
}

Real Hydrogen<0>::cp_para(Real T) {
  Real para;
  Real equil;
  Real norm;
  Real ortho;
  get_cp_(&para, &equil, &norm, &ortho, T);
  return para;
}

Real Hydrogen<0>::cp_ortho(Real T) {
  Real para;
  Real equil;
  Real norm;
  Real ortho;
  get_cp_(&para, &equil, &norm, &ortho, T);
  return ortho;
}

Real Hydrogen<0>::cp_norm(Real T) {
  Real para;
  Real equil;
  Real norm;
  Real ortho;
  get_cp_(&para, &equil, &norm, &ortho, T);
  return norm;
}

Real Hydrogen<0>::cp_equil(Real T) {
  Real para;
  Real equil;
  Real norm;
  Real ortho;
  get_cp_(&para, &equil, &norm, &ortho, T);
  return equil;
}

#undef SQUARE
#undef JMAX
