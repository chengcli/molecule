#ifndef AMMONIA_VAPORS_HPP
#define AMMONIA_VAPORS_HPP

#include <cmath>
#include "ammonia.hpp"
#include "svp_ideal.hpp"

inline Real AmmoniaVaporPressures::svpUMich(Real T) {
  Real x = -1790.00/T - 1.81630*log10(T) + 14.97593;
  return pow(10.0,x)*1.E5/760.;
}

// (164, 371.5)
inline Real AmmoniaVaporPressures::svpAntoine(Real T) {
  Real result;
  if (T < 239.6)
    result = pow(10., 3.18757 - (506.713/(T - 80.78)));
  else
    result = pow(10., 4.86886 - (1113.928/(T - 10.409)));
  return 1.E5*result;
}

// (130, 200)
inline Real AmmoniaVaporPressures::svpHubner(Real T) {
  Real A = 24.3037,
         B = -1766.28,
         C = -5.64472,
         D = 0.00740241;

  Real x = A + B/T + C*log10(T) + D*T;
  return pow(10.0, x);
}

inline Real AmmoniaVaporPressures::svpBriggsS(Real T) {
  Real a[6], x;
  if ( T < 195 ) {
    a[1] = -4122.;
    a[2] = 41.67871;
    a[3] = -1.81630;
    a[4] = 0.;
    a[5] = 0.;
  }
  else {
    a[1] = -4409.3512;
    a[2] = 76.864252;
    a[3] = -8.4598340;
    a[4] = 5.51029e-03;
    a[5] = 6.80463e-06;
  }
  x = a[1]/T + a[2] + a[3]*log(T) + a[4]*T + a[5]*pow(T, 2);
  return exp(x)/10.;
}

// (15, 195.4)
inline Real AmmoniaVaporPressures::svpFray(Real T) {
  Real a[7], x = 0;
  a[0] = 1.596e+01;
  a[1] = -3.537e+03;
  a[2] = -3.310e+04;
  a[3] = 1.742e+06;
  a[4] = -2.995e+07;
  a[5] = 0.;
  a[6] = 0.;

  for(int i = 1; i < 7; i++)
    x = x + a[i]/pow(T, i);  // best fit in [15K; 195.41K]

  return 1.E5*exp(x + a[0]);
}

inline Real AmmoniaVaporPressures::svpIdeal(Real T) {
  Real betal = 20.08,
       gammal = 5.62,
       betas = 20.64,
       gammas = 1.43,
       tripleT = 195.4,
       tripleP = 6060.;

  if (T > tripleT) {
    return SatVaporPresIdeal(T/tripleT, tripleP, betal, gammal);
  } else {
    return SatVaporPresIdeal(T/tripleT, tripleP, betas, gammas);
  }
}

#endif
