#include <iostream>
#include <math.h>

#include "Particle.h"
#include "Event.h"

// compute energy from momentum x,y,z components and invariant mass
double energy(double p_x, double p_y, double p_z, double inv_m ) {
  return sqrt(pow(p_x,2)+pow(p_y,2)+pow(p_z,2)+pow(inv_m,2));
} 

// compute invariant mass from momentum x,y,z components and energy
double inv_m(double p_x, double p_y, double p_z, double energy ) {
  return sqrt(-pow(p_x,2)-pow(p_y,2)-pow(p_z,2)+pow(energy,2));
} 

const double massPion    = 0.1395706;   // GeV/c^2
const double massProton  = 0.938272;    // GeV/c^2
const double massK0      = 0.497611;    // GeV/c^2
const double massLambda0 = 1.115683;    // GeV/c^2

double mass(const Event& e ) {

  // retrieve particles in the event
  typedef const Particle* part_ptr;
  const part_ptr* particles =e.pp ;

  // variables to loop over particles
  int i, n=e.n_particle;

  // positive / negative track counters
  int pos=0, neg=0;

  // variables for momentum sums
  double totp_x=0, totp_y=0, totp_z=0;
  // variables for energy sums, for K0 and Lambda0
  double e_k0=0, e_Lambda0=0 ;

  // loop over particles - momenta
  for (i=0; i<n; i++ ) {
    // get particle pointer
    part_ptr p=particles[i];
    // find squared momentum sums
    totp_x+=p->p_x;
    totp_y+=p->p_y;
    totp_z+=p->p_z;
    
    // update energy sums, for K0 and Lambda0 hypotheses:
    // pion mass for K0,
    // proton or pion mass for Lambda0,
    // for positive or negative particles respectively
    e_k0+=energy(p->p_x,p->p_y,p->p_z, massPion);
    
    e_Lambda0+=energy(p->p_x,p->p_y,p->p_z,(p->charge > 0)? massProton : massPion);
    // update positive/negative track counters
    if(p->charge >0) pos++;
    else if(p->charge <0) neg++;
    else {return 0;}     //could find 0 charge
  }

  // check for exactly one positive and one negative track
  // otherwise return negative (unphysical) invariant mass
  if(pos!=1||neg!=1) return 0;

  // invariant masses for different decay product mass hypotheses
  double mk0=inv_m(totp_x, totp_y, totp_z, e_k0);
  double mLambda0=inv_m(totp_x, totp_y, totp_z, e_Lambda0);

  if( fabs(massK0-mk0) == fabs(massLambda0-mLambda0)) return 0; //inconsistent test
  // compare invariant masses with known values and return the nearest one
  if(fabs(massK0-mk0) < fabs(massLambda0-mLambda0))  return mk0;
  else{return mLambda0;}    

}

