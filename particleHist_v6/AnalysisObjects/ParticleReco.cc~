#include "ParticleReco.h"
#include "utilities.h"
#include "Constants.h"
#include <iostream>
#include <cmath>

using namespace std;

 
// constructor
ParticleReco::ParticleReco() {
}


// destructor
ParticleReco::~ParticleReco() {
}


// recompute tag informations for new event
void ParticleReco::update( const Event& e ) {

  // set default quantities
  type = unknown;
  particleEnergy = -1;
  particleMass   = -1;

  // code to compute total energy and invariant mass for the two
  // mass hypotheses for the decay products
   // variables to loop over particles
  int i, n=e.get_n_particle();

  // positive / negative track counters
  int pos=0, neg=0;

  // variables for momentum sums
  double totp_x=0, totp_y=0, totp_z=0;
  // variables for energy sums, for K0 and Lambda0
  double e_k0=0, e_Lambda0=0 ;

  // loop over particles - momenta
  for (i=0; i<n; i++ ) {
    // get particle pointer
    const Event::part_ptr p=e.get_particle(i);
    // find squared momentum sums
    totp_x+=p->p_x;
    totp_y+=p->p_y;
    totp_z+=p->p_z;
    
    // update energy sums, for K0 and Lambda0 hypotheses:
    // pion mass for K0,
    // proton or pion mass for Lambda0,
    // for positive or negative particles respectively
    e_k0+=utilities::energy(p->p_x,p->p_y,p->p_z,Constants:: massPion);
    
    e_Lambda0+=utilities::energy(p->p_x,p->p_y,p->p_z,(p->charge > 0)?Constants:: massProton :Constants:: massPion);
    // update positive/negative track counters
    if(p->charge >0) pos++;
    else if(p->charge <0) neg++;
    else {return ;}     //could find 0 charge
  }

  // compare invariant masses with known values and set final values
  // ( type, energy and mass )
  
 // check for exactly one positive and one negative track
  // otherwise return negative (unphysical) invariant mass
  if(pos!=1||neg!=1) return ;

  // invariant masses for different decay product mass hypotheses
  double mk0= utilities:: inv_m(totp_x, totp_y, totp_z, e_k0);
  double mLambda0= utilities:: inv_m(totp_x, totp_y, totp_z, e_Lambda0);

  if( fabs(Constants::massK0-mk0) == fabs(Constants::massLambda0-mLambda0)) return ; //inconsistent test
  // compare invariant masses with known values and return the nearest one
  if(fabs(Constants::massK0-mk0) < fabs(Constants::massLambda0-mLambda0)) {
    particleMass = mk0;
    particleEnergy = e_k0;
    type = K0;
  }
  else{
    particleMass = mLambda0;
    particleEnergy = e_Lambda0;
    type = Lambda0;
  }

  return;

}


// return particle type
ParticleReco::ParticleType ParticleReco::get_particleType() {
  // check for new event and return result
  check();
  return type;
}


// return particle energy
double ParticleReco::get_particleEnergy() {
  // check for new event and return result
  check();
  return particleEnergy;
}


// return particle mass
double ParticleReco::get_particleMass() {
  // check for new event and return result
  check();
  return particleMass;
}

