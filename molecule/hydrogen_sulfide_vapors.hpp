#ifndef HYDROGEN_SULFIDE_VAPORS_HPP
#define HYDROGEN_SULFIDE_VAPORS_HPP

#include <cmath>
#include "hydrogen_sulfide.hpp"

inline Real HydrogenSulfideVaporPressures::svpAntoine(Real T)
{
    Real result;
    if (T < 212.8)
        result = pow(10., 4.43681 - (829.439 / (T - 25.412)));
    else
        result = pow(10., 4.52887 - (958.587 / (T - 0.539)));

    return 1.E5 * result;
}

#endif
