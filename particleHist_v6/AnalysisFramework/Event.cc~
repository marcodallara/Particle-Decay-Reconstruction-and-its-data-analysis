#include "Event.h"

Event::Event( int n, double X, double Y, double Z ):
  ev_id(n),
  x(X),
  y(Y),
  z(Z) {
  // allocate a buffer for  particle pointers 
  pp.reserve(10);
  
}


Event::~Event() {
  // delete particles
  for(unsigned int i=0;i<pp.size();i++) delete pp.at(i);
;
}


void Event::add( int charg, double px, double py, double pz ) {

  // check for the number of particles, if maximum reached do nothing
  // and return
  if(pp.size()>= 10) return ;
  

  // create the new particle and fill with data
  
  Particle p{charg, px, py, pz};
 
  // alocate and store particle
  pp.push_back(new const Particle(p));


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

