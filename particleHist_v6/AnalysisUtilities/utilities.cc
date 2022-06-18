#include "AnalysisUtilities/utilities.h"
#include <math.h>

// compute energy from momentum x,y,z components and invariant mass
double utilities:: energy(double p_x, double p_y, double p_z, double inv_m ) {
  return sqrt(pow(p_x,2)+pow(p_y,2)+pow(p_z,2)+pow(inv_m,2));
} 

// compute invariant mass from momentum x,y,z components and energy
double utilities:: inv_m(double p_x, double p_y, double p_z, double energy ) {
  return sqrt(-pow(p_x,2)-pow(p_y,2)-pow(p_z,2)+pow(energy,2));
} 
