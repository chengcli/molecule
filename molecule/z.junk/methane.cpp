/** @file methane.cpp
 * @brief
 *
 * @author Cheng Li (chengcli@umich.edu)
 * @date Tuesday Jul 13, 2021 15:26:31 PDT
 * @bug No known bugs.
 */

#include <stdexcept>
#include <sstream>
#include "molecules.hpp"

double Methane::nist_shomate1_[7] =  {
};

double Methane::nist_shomate2_[7] = {
};

double Methane::cp_nist(double T) {
  double *pdata;
  std::stringstream msg;
  //if (T < 298. || T > 6000.) {
  //  msg << "ERROR: Temperature out of range in Methane::cp_nist" << std::endl;
  //  throw std::runtime_error(msg.str().c_str());
  //}


  double result;
  T /= 1.E3;
  result = pdata[0] + pdata[1]*T + pdata[2]*T*T + pdata[3]*T*T*T + pdata[4]/(T*T);
  return result;
}

Methane aCH4;
