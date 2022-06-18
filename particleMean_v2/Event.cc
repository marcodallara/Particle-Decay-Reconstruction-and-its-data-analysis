#include "Event.h"

Event::Event( int n, float X, float Y, float Z ):
  ev_id(n),
  x(X),
  y(Y),
  z(Z),
  n_particle(0),
  partNum_max(10){
  // allocate a buffer for particle pointers
  pp= new part_ptr[partNum_max];
  
  
}


Event::~Event() {
  // delete all the particle 
  for(int i=0;i<n_particle;i++) delete pp[i];
  // delete the array of pointers
  delete[] pp;
}


void Event::add( int charg, float px, float py, float pz ) {

  // check for the number of particles, if maximum reached do nothing
  // and return
  if(n_particle>= partNum_max) return ;
  

  // create the new particle and fill with data
  
  Particle p{charg, px, py, pz};
 
  // alocate and store the new particle and increase counter
  pp[n_particle]= new const Particle(p);
  n_particle++;

  return;

}


// get event id.
int Event::get_ev_id() const {
  return ev_id;
}


// get decay point coordinates
double Event::get_x() const {
  return x;
}
// get decay point coordinates
double Event::get_y() const {
  return y;
}
// get decay point coordinates
double Event::get_z() const {
  return z;
}


// get number of particles
int Event::get_n_particle() const {
  return n_particle;
}


// get particle
const Event::Particle* Event::get_particle( unsigned int i ) const {
  return pp[i];
}

