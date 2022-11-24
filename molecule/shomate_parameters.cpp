// molecules
#include <configure.hpp>
#include "molecules.hpp"

// dummy shomate
Real const DummySpecies<0>::shomate1_[7] = {1., 0., 0., 0., 0., 0., 0.};

// hydrogen
// 298 ~ 1000 K
Real const Hydrogen<0>::shomate1_[7] = {
  33.066178, -11.363417, 11.432816, -2.772874, -0.158558, -9.980797, 172.707974};

// 1000 ~ 2500 K
Real const Hydrogen<0>::shomate2_[7] = {
  18.563083, 12.257357, -2.859786, 0.268238, 1.977990, -1.147438, 156.288133};

// 2500 ~ 6000 K
Real const Hydrogen<0>::shomate3_[7] = {
  43.413560, -4.293079, 1.272428, -0.096876, -20.533862, -38.515158, 162.081354};

// helium
// 300 ~ 600 K
Real const Helium<0>::shomate1_[7] = {
  20.78603, 4.850638E-10, -1.582916E-10, 1.525102E-11, 3.196347E-11, -6.197341, 151.3064};

// methane
// 298 ~ 1300 K
Real const Methane<0>::shomate1_[7] = {
  -0.703029, 108.4773, -42.52157, 5.862788, 0.678565, -76.84376, 158.7163};

// 1300 ~ 6000 K
Real const Methane<0>::shomate2_[7] = {
  85.81217, 11.26467, -2.114146, 0.138190, -26.42221, -153.5327, 224.4143};

Real const Methane<1>::shomate1_[7] = {52.93, 0., 0., 0., 0., 0., 0.};

Real const Methane<2>::shomate1_[7] = {43.55, 0., 0., 0., 0., 0., 0.};

// water
// 500 ~ 1700 K
Real const Water<0>::shomate1_[7] = {
  30.09200, 6.832514, 6.793435, -2.534480, 0.082139, -250.8810, 223.3957};

// 1700 ~ 6000 K
Real const Water<0>::shomate2_[7] = {
  41.96426, 8.622053, -1.499780, 0.098119, -11.15764, -272.1797, 219.7809};

Real const Water<1>::shomate1_[7] = {75.6, 0., 0., 0., 0., 0., 0.};

Real const Water<2>::shomate1_[7] = {37.8, 0., 0., 0., 0., 0., 0.};

// ammonia
// 298 ~ 1300 K
Real const Ammonia<0>::shomate1_[7] = {
  19.99563, 49.77119, -15.37599, 1.921168, 0.189174, -53.30667, 203.8591};

// 1300 ~ 6000 K
Real const Ammonia<0>::shomate2_[7] = {
  52.02427, 18.48801, -3.765128, 0.248541, -12.45799, -85.53895, 223.8022};

Real const Ammonia<1>::shomate1_[7] = {65.0, 0., 0., 0., 0., 0., 0.};

Real const Ammonia<2>::shomate1_[7] = {46.0, 0., 0., 0., 0., 0., 0.};

// hydrogen sulfide
// 298 ~ 1400 K
Real const HydrogenSulfide<0>::shomate1_[7] = {
  26.88412, 18.67809, 3.434203, -3.378702, 0.135882, -28.91211, 233.3747};

// 1400 ~ 6000 K
Real const HydrogenSulfide<0>::shomate2_[7] = {
  51.22136, 4.147486, -0.643566, 0.041621, -10.46385, -55.87606, 243.6900};

Real const HydrogenSulfide<1>::shomate1_[7] = {66.4, 0., 0., 0., 0., 0., 0.};

Real const HydrogenSulfide<2>::shomate1_[7] = {33.2, 0., 0., 0., 0., 0., 0.};
