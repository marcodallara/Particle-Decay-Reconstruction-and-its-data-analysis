#include "Event.h"

Event::Event( int n, float X, float Y, float Z ):
  ev_id(n),
  x(X),
  y(Y),
  z(Z) {
  // allocate a buffer for particle pointers
  pp.reserve(10);
  //for(int i=0; i<partNum_max; i++) pp[i]= new Particle;
  
}


Event::~Event() {
  // delete all the particle pointers
  for(unsigned int i=0;i<pp.size();i++) delete pp.at(i);
  // delete the pointers array
  //delete[] pp;
}


void Event::add( int charg, float px, float py, float pz ) {

  // check for the number of particles, if maximum reached do nothing
  // and return
  if(pp.size()>= 10) return ;
  

  // create the new particle and fill with data
  
  Particle p{charg, px, py, pz};
 /* p.charge= charg;
  p.p_x= px;
  p.p_y= py;
  p.p_z= pz;
 */
  // alocate and store the new particle pointer in the array and increase counter
  pp.push_back(new const Particle(p));
  // *(pp[n_particle])=p;
  
  //n_particle++;

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
  return pp.size();
}


// get particle
const Event::Particle* Event::get_particle( unsigned int i ) const {
  return pp.at(i);
}

