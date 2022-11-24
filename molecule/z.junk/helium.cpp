/** @file helium.cpp
 * @brief
 *
 * @author Cheng Li (chengcli@umich.edu)
 * @date Tuesday Jul 13, 2021 15:26:31 PDT
 * @bug No known bugs.
 */

#include <stdexcept>
#include <sstream>
#include "molecules.hpp"

Real Helium::cp_nist(Real T) {
  std::stringstream msg;
  T = std::min(std::max(298., T), 600.);
  //if (T < 298. || T > 600.) {
  //  msg << "ERROR: Temperature out of range in Helium::cp_nist" << std::endl;
  //  throw std::runtime_error(msg.str().c_str());
  //}

  Real *pdata = nist_shomate_;
  Real result;
  T /= 1.E3;
  result = pdata[0] + pdata[1]*T + pdata[2]*T*T + pdata[3]*T*T*T + pdata[4]/(T*T);
  return result;
}

Helium aHe;
