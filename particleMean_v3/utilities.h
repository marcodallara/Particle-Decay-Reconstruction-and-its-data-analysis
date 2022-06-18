#ifndef utilities_h
#define utilities_h

class utilities {
 public:

// compute energy from momentum x,y,z components and invariant mass

  static double energy(double p_x, double p_y, double p_z, double inv_m );

// compute energy from momentum x,y,z components and invariant mass

  static double inv_m(double p_x, double p_y, double p_z, double energy );

  
};

#endif
