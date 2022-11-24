#ifndef SVP_IDEAL_HPP
#define SVP_IDEAL_HPP

/*! Ideal saturation vapor pressure
 *
 * $p^* = p^r\exp[\beta(1-1/t)-\delta\lnt]$
 * $p^r$ is the reference pressure, usually choosen to be the triple point pressure \n
 * $t=T/T^r$ is the dimensionless temperature. $T^r$ is the reference temperature. \n
 * Similar to $p^r$, $T^r$ is usually choosen to be the triple point temperature
 * @return $p^*$ [pa]
 */
inline Real SatVaporPresIdeal(Real t, Real p3, Real beta, Real delta) {
  return p3*exp((1. - 1./t)*beta - delta*log(t));
}

#endif
