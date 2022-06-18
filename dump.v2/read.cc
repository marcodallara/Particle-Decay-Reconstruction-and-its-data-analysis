#include <iostream>
#include <fstream>

#include "Event.h"
#include "Particle.h"

//read data's from a file
const Event* read( std::ifstream& in){

  Event* e;
  double i;
  if( in>>i ) e = new  Event; 
  else return nullptr;  // on failure return null pointer
  e->ev_id = i; 
  //read and copy x
  in>>i;
  e->x = i;
  //read and copy y 
  in>>i;
  e->y = i;
  //read and copy z
  in>>i;
  e->z = i;
  //read and number of particles
  int n;
  in>>n;
  e->n_particle = n;
  
  e->p = new Particle*[n];
  for(int i=0;i<n;i++){   //set particle's data
    (e->p[i]) = new Particle;
    in>> (e->p[i])->charge;
    in>> (e->p[i])->p_x;
    in>> (e->p[i])->p_y;
    in>> (e->p[i])->p_z;
  }

  return e;

}
