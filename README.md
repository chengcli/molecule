# Purpose of the molecule package.

The Molecule package tries to abstract out the messy thermodynamics of the cloudy
process.

The fundamental class is the Molecule class that provides access to four fundamenta
thermodynamic properties:

cp(T),returns heat capacity at a temperature
entropy(T), returns the relative entropy to a reference state
enthalpy(T), returns the relative enthalpy
svp(T), returns the saturation vapor pressure

The reference state can be set by the function, setReferenceTemperature(T)

Non-ideal heat capacities are implemented via the shomate equations.
There might be multiple shomate coefficients for different temperature ranges.
Each temperature range has one pointer that stores the shomate coefficients.
These coefficients are stored privately in the individual class that implements Molecule.
From the side of Molecule, shomate\_func\_ptr\_ is used to select the shomate
coefficient pointer based on temperature T. The shomate\_func\_ptr\_ is set by the
derived class.

The derived class should set three variables of the parent class in the constructor
1) phase\_id\_
2) shomate\_func\_ptr\_
3) svp\_func\_ptr\_
