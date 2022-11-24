/** @file test_molecules.cpp
 * @brief
 *
 * @author Cheng Li (chengcli@umich.edu)
 * @date Tuesday Jul 13, 2021 14:20:17 PDT
 * @bug No known bugs.
 */

#include <iostream>
#include <molecule/molecules.hpp>

using namespace std;

int main() {
	double T = 1200.;

  Hydrogen<0>         H2;
  Helium<0>           He;
  Methane<0>          CH4;
  Water<0>            H2O;
  Ammonia<1>          NH3;
  HydrogenSulfide<2>  H2S;

  H2.setReferenceTemperature(300.);
  He.setReferenceTemperature(300.);
  CH4.setReferenceTemperature(300.);
  H2O.setReferenceTemperature(300.);
  NH3.setReferenceTemperature(300.);
  H2S.setReferenceTemperature(300.);

  std::cout << H2.fpara_equil(T) << std::endl;
  std::cout << H2.cp_para(T) << std::endl;
  std::cout << H2.cp_ortho(T) << std::endl;
  std::cout << H2.cp_norm(T) << std::endl;
  std::cout << H2.cp_equil(T) << std::endl;
  std::cout << H2.cp(T) << std::endl;
	std::cout << std::endl;

  std::cout << He.cp(100.) << std::endl;
  std::cout << He.cp(300.) << std::endl;
  std::cout << He.cp(500.) << std::endl;
  std::cout << He.cp(1000.) << std::endl;
	std::cout << std::endl;

  std::cout << CH4.cp(300.) << std::endl;
  std::cout << CH4.cp(1299.) << std::endl;
  std::cout << CH4.enthalpy(1301.) << std::endl;
  std::cout << CH4.entropy(1301.) << std::endl;
	std::cout << std::endl;

  std::cout << H2O.cp(300.) << std::endl;
  std::cout << H2O.enthalpy(500.) << std::endl;
  std::cout << H2O.entropy(500.) << std::endl;
	std::cout << std::endl;

  std::cout << NH3.cp(100.) << std::endl;
  std::cout << NH3.enthalpy(100.) << std::endl;
  std::cout << NH3.entropy(100.) << std::endl;
	std::cout << std::endl;

  std::cout << H2S.cp(100.) << std::endl;
  std::cout << H2S.enthalpy(100.) << std::endl;
  std::cout << H2S.entropy(100.) << std::endl;
}
